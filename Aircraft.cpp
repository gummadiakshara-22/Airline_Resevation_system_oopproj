#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include "Seat.cpp"
#include "Time.cpp"
using namespace std;
class Aircraft {
    protected:
        string ID, Name;
        int totalSeats, businessSeats, economySeats;
        int availableBusinessSeats, availableEconomySeats;
        string startingPoint, destination;
        vector<Seat> businessClassSeats, economyClassSeats;
        Time departureTime, arrivalTime;
    
    public:
        Aircraft(string id, string name)
            : ID(id), Name(name), totalSeats(0), businessSeats(0), economySeats(0),
              availableBusinessSeats(0), availableEconomySeats(0),
              startingPoint("NULL"), destination("NULL") {}
    
        virtual ~Aircraft() {}
    
        string getID() const { return ID; }
    
        virtual void flightDetails() const {
            cout << "\nFlight Name: " << Name << " - " << ID << endl;
            cout << "Starting Point: " << startingPoint << endl;
            cout << "Destination: " << destination << endl;
            cout << "Available Business Seats: " << availableBusinessSeats << endl;
            cout << "Available Economy Seats: " << availableEconomySeats << endl;
        }
    
        virtual void updateFlightDetails() {
            string password;
            cout << "Enter Manager Password: ";
            cin >> password;
            if (password != "UST") {
                cout << "Invalid Password!" << endl;
                return;
            }
    
            cout << "Enter Starting Point: ";
            cin >> startingPoint;
            cout << "Enter Destination: ";
            cin >> destination;
    
            int h, m;
            string d;
            cout << "Enter Departure Time (hours minutes day): ";
            cin >> h >> m >> d;
            departureTime = Time(h, m, d);
    
            cout << "Enter Arrival Time (hours minutes day): ";
            cin >> h >> m >> d;
            arrivalTime = Time(h, m, d);
    
            do {
                cout << "Enter Number of Business Seats: ";
                cin >> businessSeats;
                cout << "Enter Number of Economy Seats: ";
                cin >> economySeats;
                totalSeats = businessSeats + economySeats;
                if (totalSeats < 100 || totalSeats > 300) {
                    cout << "Total seats must be between 100 and 300. Try again.\n";
                }
            } while (totalSeats < 100 || totalSeats > 300);
    
            availableBusinessSeats = businessSeats;
            availableEconomySeats = economySeats;
    
            businessClassSeats.resize(businessSeats);
            economyClassSeats.resize(economySeats);
    
            for (int i = 0; i < businessSeats; ++i) {
                businessClassSeats[i].setSeatNumber(i + 1);
            }
            for (int i = 0; i < economySeats; ++i) {
                economyClassSeats[i].setSeatNumber(i + 1);
            }
        }
    
        virtual void reserveTicket() {
            int choice;
            cout << "Enter 1 for Business Class, 2 for Economy Class: ";
            cin >> choice;
    
            if (choice == 1 && availableBusinessSeats > 0) {
                for (auto &seat : businessClassSeats) {
                    if (!seat.isBooked()) {
                        seat.bookSeat();
                        availableBusinessSeats--;
                        break;
                    }
                }
            } else if (choice == 2 && availableEconomySeats > 0) {
                for (auto &seat : economyClassSeats) {
                    if (!seat.isBooked()) {
                        seat.bookSeat();
                        availableEconomySeats--;
                        break;
                    }
                }
            } else {
                cout << "No seats available in the selected class.\n";
            }
        }
    virtual void generateBookingSummary() const {
        string fileName = ID + "_BookingSummary.txt";
        ofstream outFile(fileName);

        if (!outFile) {
            cout << "Error: Could not create the booking summary file.\n";
            return;
        }

        outFile << "Booking Summary for Flight: " << Name << " - " << ID << "\n";
        outFile << "Starting Point: " << startingPoint << "\n";
        outFile << "Destination: " << destination << "\n";
        outFile << "Departure Time: ";
        departureTime.display();
        outFile << "\nArrival Time: ";
        arrivalTime.display();
        outFile << "\n\n";

        outFile << "Business Class Bookings:\n";
        for (const auto &seat : businessClassSeats) {
            if (seat.isBooked()) {
                outFile << "Seat Number: " << seat.getSeatNumber() << "\n";
                outFile << "Passenger Name: " << seat.getPassengerName() << "\n";
                outFile << "Passenger Age: " << seat.getPassengerAge() << "\n";
                outFile << "Reservation Number: " << seat.getReservationNumber() << "\n\n";
            }
        }

        outFile << "Economy Class Bookings:\n";
        for (const auto &seat : economyClassSeats) {
            if (seat.isBooked()) {
                outFile << "Seat Number: " << seat.getSeatNumber() << "\n";
                outFile << "Passenger Name: " << seat.getPassengerName() << "\n";
                outFile << "Passenger Age: " << seat.getPassengerAge() << "\n";
                outFile << "Reservation Number: " << seat.getReservationNumber() << "\n\n";
            }
        }

        outFile.close();
        cout << "Booking summary has been saved to " << fileName << "\n";
    }
    
        virtual void cancelTicket(const string &reservationNumber) {
            for (auto &seat : businessClassSeats) {
                if (seat.getReservationNumber() == reservationNumber) {
                    seat.unBookSeat();
                    availableBusinessSeats++;
                    cout << "Ticket Cancelled.\n";
                    return;
                }
            }
            for (auto &seat : economyClassSeats) {
                if (seat.getReservationNumber() == reservationNumber) {
                    seat.unBookSeat();
                    availableEconomySeats++;
                    cout << "Ticket Cancelled.\n";
                    return;
                }
            }
            cout << "Reservation Number not found.\n";
        }
    
        virtual void flightSchedule() const {
            cout << Name << " - " << ID << "\t" << startingPoint << "\t" << destination << "\t";
            departureTime.display();
            cout << "\t";
            arrivalTime.display();
            cout << endl;
        }
    };
    
    class INDIGO : public Aircraft {
    public:
        INDIGO() : Aircraft("6E25", "Indigo") {}
    };
    
    class AIRINDIA : public Aircraft {
    public:
        AIRINDIA() : Aircraft("AI25", "AirIndia") {}
    };
    
    class SPICEJET : public Aircraft {
    public:
        SPICEJET() : Aircraft("SP25", "SpiceJet") {}
    };
    
    class VISTARA : public Aircraft {
    public:
        VISTARA() : Aircraft("VI25", "Vistara") {}
    };
    