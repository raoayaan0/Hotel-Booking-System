#include <iostream>
#include <fstream>
using namespace std;

int main() {
    // RAM Simulation (Memory)
    int rooms[5] = {0, 0, 0, 0, 0}; // 0 = Free, 1 = Booked
    string name;
    int roomNumber;
    char choice;

    do {
        cout << "\nEnter Customer Name: ";
        cin >> name;

        // Show available rooms
        cout << "\nAvailable Rooms:\n";
        bool anyFree = false;
        for(int i = 0; i < 5; i++) {
            if(rooms[i] == 0) {
                cout << "Room " << i << " is Free\n";
                anyFree = true;
            }
        }

        if(!anyFree) {
            cout << "Sorry! No rooms are available.\n";
            break;
        }

        // Input validation
        do {
            cout << "\nEnter Room Number (0-4): ";
            cin >> roomNumber;
            if(roomNumber < 0 || roomNumber > 4)
                cout << "Invalid Room Number. Try again.\n";
        } while(roomNumber < 0 || roomNumber > 4);

        // Check and Book
        if(rooms[roomNumber] == 0) {
            rooms[roomNumber] = 1; // Memory Update
            cout << "Room Booked Successfully!\n";

            // Save to Secondary Storage
            ofstream file("booking.txt", ios::app);
            file << name << " booked Room " << roomNumber << endl;
            file.close();
        }
        else {
            cout << "Room Already Booked!\n";
        }

        // Ask if user wants to view booking history
        cout << "Do you want to view booking history? (y/n): ";
        cin >> choice;
        if(choice == 'y' || choice == 'Y') {
            string line;
            ifstream file("booking.txt");
            cout << "\n--- Booking History ---\n";
            while(getline(file, line)) {
                cout << line << endl;
            }
            file.close();
        }

        cout << "\nDo you want another booking? (y/n): ";
        cin >> choice;

    } while(choice == 'y' || choice == 'Y');

    cout << "Thank you for using the Hotel Booking System!\n";
    return 0;
}