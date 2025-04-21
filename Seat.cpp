#include<iostream>
using namespace std;
class Seat {
    string passenger_name;
    int passenger_age;
    int seat_number;
    bool booked;
    string reservation_number;

public:
    Seat() : passenger_name("NULL"), passenger_age(0), seat_number(0), booked(false), reservation_number("") {}

    bool isBooked() const { return booked; }
    void setSeatNumber(int num) { seat_number = num; }

    void bookSeat() {
        cin.ignore();
        cout << "Enter Passenger's Name: ";
        getline(cin, passenger_name);
        cout << "Enter Passenger's Age: ";
        cin >> passenger_age;
        booked = true;
        reservation_number = passenger_name.substr(0, 3) + to_string(passenger_age);
        cout << "Reservation Number: " << reservation_number << endl;
    }

    void unBookSeat() {
        passenger_name = "NULL";
        passenger_age = 0;
        booked = false;
        reservation_number = "";
    }

    string getReservationNumber() const { return reservation_number; }
    int getSeatNumber() const { return seat_number; }
    string getPassengerName() const { return passenger_name ;}
    int getPassengerAge() const { return passenger_age; }
    void displayDetails(bool isEconomy) const {
        cout << "Passenger Name: " << passenger_name << endl;
        cout << "Passenger Age: " << passenger_age << endl;
        cout << "Seat Number: " << seat_number << endl;
        cout << "Seat Type: " << (isEconomy ? "Economy" : "Business") << endl;
        cout << "Booked Status: " << (booked ? "Booked" : "Vacant") << endl;
        cout << "Reservation Number: " << reservation_number << endl;
    }

};