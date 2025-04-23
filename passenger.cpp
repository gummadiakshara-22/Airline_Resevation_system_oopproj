#include<iostream>
#include<string>
using namespace std;
class Passenger {
        string name;
        int age;
        string unique_id;
    public:
    Passenger() : name ("NULL"), age(0), unique_id("NULL") {}
    void setPassenger(string name, int age, string unique_id) {
        this->name = name;
        this->age = age;
        this->unique_id = unique_id;
    }
    string get_passengername() {
        return name;}
    int get_passengerage() {
        return age;}
    string get_passengerid() {
        return unique_id;}

    };