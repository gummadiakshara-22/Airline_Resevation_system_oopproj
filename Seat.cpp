#include<iostream>
using namespace std;
#include"passenger.cpp"
class Seat {
    Passenger passenger;
    int seat_number;
    bool booked;
    string reservation_number;

public:
    Seat() : seat_number(0), booked(false), reservation_number("") {}

    bool isBooked() const { return booked; }
    void setSeatNumber(int num) { seat_number = num; }

    void bookSeat() {
        cin.ignore();
        cout << "Enter Passenger's Name: ";
        string p;
        getline(cin, p);
        cout << "Enter Passenger's Age: ";
        int a;
        cin >> a;
        passenger.setPassenger(p, a);
        booked = true;
        setReservationNumber(passenger);
        cout << "Booking Confirmed. Your PNR is "<< reservation_number << endl;
        }
    void setReservationNumber(Passenger p){
        reservation_number = p.get_passengername().substr(0,3) + to_string(seat_number);
    }
    void unBookSeat() {
        passenger.setPassenger("NULL", 0 );
        booked = false;
        reservation_number = "";
    }

    string getReservationNumber() const { return reservation_number; }
    int getSeatNumber() const { return seat_number; }
    void displayDetails(bool isEconomy)  {
        cout << "Passenger Name: " << passenger.get_passengername() << endl;
        cout << "Passenger Age: " << passenger.get_passengerage() << endl;
        cout << "Seat Number: " << seat_number << endl;
        cout << "Seat Type: " << (isEconomy ? "Economy" : "Business") << endl;
        cout << "Booked Status: " << (booked ? "Booked" : "Vacant") << endl;
        cout << "Reservation Number: " << reservation_number << endl;
    }
    
    string getPassengerName()  { return passenger.get_passengername(); }
    int getPassengerAge()  { return passenger.get_passengerage(); }

};
