#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip> // For formatted output
using namespace std;

class Time {
    int hours, minutes;
    string day;

public:
    Time() : hours(0), minutes(0), day("") {}
    Time(int h, int m, string d) : hours(h), minutes(m), day(d) {}

    int getHours() const { return hours; }
    int getMinutes() const { return minutes; }
    string getDay() const { return day; }

    void display() const {
        cout << setw(2) << setfill('0') << hours << ":"
             << setw(2) << setfill('0') << minutes;
    }
};