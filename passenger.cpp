#include<iostream>
#include<string>
using namespace std;
class Passenger {
        string name;
        int age;
    public:
    Passenger() : name ("NULL"), age(0) {}
    void setPassenger(string name, int age) {
        this->name = name;
        this->age = age;
    }
    string get_passengername() {
        return name;}
    int get_passengerage() {
        return age;
    }

    };
