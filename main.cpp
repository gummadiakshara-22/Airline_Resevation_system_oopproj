#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "Aircraft.cpp"

using namespace std;

int main() {
    vector<Aircraft *> flights = {new INDIGO(), new AIRINDIA(), new SPICEJET(), new VISTARA()};

    int menu = 0;
    while (menu != 6) {
        cout << "\nFLIGHT SCHEDULE\n";
        for (const auto &flight : flights) {
            flight->flightSchedule();
        }

        cout << "\nMAIN MENU\n";
        cout << "1. Flight Details\n";
        cout << "2. Update Flight Details\n";
        cout << "3. Reserve a Ticket\n";
        cout << "4. Cancel a Ticket\n";
        cout << "5. Generate Booking Summary\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> menu;

        if (menu == 1) {
            string id;
            cout << "Enter Aircraft ID: ";
            cin >> id;
            for (const auto &flight : flights) {
                if (flight->getID() == id) {
                    flight->flightDetails();
                    break;
                }
            }
        } else if (menu == 2) {
            string id;
            cout << "Enter Aircraft ID: ";
            cin >> id;
            for (const auto &flight : flights) {
                if (flight->getID() == id) {
                    flight->updateFlightDetails();
                    break;
                }
            }
        } else if (menu == 3) {
            string id;
            cout << "Enter Aircraft ID: ";
            cin >> id;
            for (const auto &flight : flights) {
                if (flight->getID() == id) {
                    flight->reserveTicket();
                    break;
                }
            }
        } else if (menu == 4) {
            string id, reservationNumber;
            cout << "Enter Aircraft ID: ";
            cin >> id;
            cout << "Enter Reservation Number: ";
            cin >> reservationNumber;
            for (const auto &flight : flights) {
                if (flight->getID() == id) {
                    flight->cancelTicket(reservationNumber);
                    break;
                }
            }
        } else if (menu == 5) {
            string id;
            cout << "Enter Aircraft ID: ";
            cin >> id;
            for (const auto &flight : flights) {
                if (flight->getID() == id) {
                    flight->generateBookingSummary();
                    break;
                }
            }
        } else if (menu == 6) {
            cout << "Exiting the program. Thank you!\n";
        } else {
            cout << "Invalid choice. Please try again.\n";
        }
    }

    for (auto &flight : flights) {
        delete flight;
    }

    return 0;
}
