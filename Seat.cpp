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
        cout<<"Enter Passenger's Unique ID(up to 4char): ";
        cin.ignore();
        string id;
        getline(cin, id);
        passenger.setPassenger(p, a, id);
        booked = true;
        setReservationNumber(passenger);
        cout << "Booking Confirmed. Your PNR is "<< reservation_number << endl;}
    void setReservationNumber(Passenger p){
        reservation_number = p.get_passengername().substr(0,3)+p.get_passengerid() ;
    }
    void unBookSeat() {
        passenger.setPassenger("NULL", 0 , "NULL");
        booked = false;
        reservation_number = "";
    }

    string getReservationNumber() const { return reservation_number; }
    int getSeatNumber() const { return seat_number; }
    int getindex(string pnr){
        
    }
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
    string getPassengerID()  { return passenger.get_passengerid(); }

};
