#include <ctime>
#include <cstring>
#include <cstdlib>
#include <sstream>
#include <fstream>   

bool isAllDigits(const char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9') return false;
    }
    return strlen(str) > 0;
}

bool isAllLetters(const char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))) return false;
    }
    return strlen(str) > 0;
}
// ---------- main ----------
// kushal final version
// -------------------------

#include <iostream>

using namespace std;

class Room {
protected:
    int roomNo;
    char guestName[30];
    char phone[15];
    int days;

public:
    Room() {
        roomNo = 0;
        guestName[0] = '\0';
        phone[0] = '\0';
        days = 0;
    }

    void inputCommon() {
        cout << "Enter room number: ";
        cin >> roomNo;

        cout << "Enter guest name (one word): ";
        cin >> guestName;

        cout << "Enter phone (digits only): ";
        cin >> phone;

        cout << "Enter number of days: ";
        cin >> days;
    }

    virtual double getRatePerDay() const = 0;
    virtual const char* getType() const = 0;

    double totalCost() const {
        return days * getRatePerDay();
    }

    int getRoomNo() const { return roomNo; }

    void show() const {
        cout << "Room No   : " << roomNo << "\n";
        cout << "Type      : " << getType() << "\n";
        cout << "Guest     : " << guestName << "\n";
        cout << "Phone     : " << phone << "\n";
        cout << "Days      : " << days << "\n";
        cout << "Rate/Day  : " << getRatePerDay() << "\n";
        cout << "Total Bill: " << totalCost() << "\n";
    }

    virtual ~Room() {}
};

class DeluxeRoom : public Room {
public:
    double getRatePerDay() const override {
        return 1000.0;
    }
    const char* getType() const override {
        return "Deluxe";
    }
};

class ExecutiveRoom : public Room {
public:
    double getRatePerDay() const override {
        return 1500.0;
    }
    const char* getType() const override {
        return "Executive";
    }
};

class PresidentialRoom : public Room {
public:
    double getRatePerDay() const override {
        return 2500.0;
    }
    const char* getType() const override {
        return "Presidential";
    }
};

class Hotel {
    Room* bookings[100];
    int count;

public:
    Hotel() : count(0) {
        for (int i = 0; i < 100; i++) bookings[i] = nullptr;
    }

    void bookRoom() {
        if (count >= 100) {
            cout << "Hotel full.\n";
            return;
        }

        int choice;
        cout << "\n1. Deluxe  2. Executive  3. Presidential\nChoice: ";
        cin >> choice;

        Room* r = nullptr;
        if (choice == 1) r = new DeluxeRoom();
        else if (choice == 2) r = new ExecutiveRoom();
        else if (choice == 3) r = new PresidentialRoom();
        else {
            cout << "Invalid.\n";
            return;
        }

        r->inputCommon();
        bookings[count++] = r;
        cout << "Booked.\n";
    }

    void showAll() {
        if (count == 0) {
            cout << "No bookings.\n";
            return;
        }
        for (int i = 0; i < count; i++) {
            cout << "\n--- Booking " << (i+1) << " ---\n";
            bookings[i]->show();
        }
    }

    void searchByRoom() {
        if (count == 0) {
            cout << "No bookings.\n";
            return;
        }
        int rno;
        cout << "Room number: ";
        cin >> rno;
        for (int i = 0; i < count; i++) {
            if (bookings[i]->getRoomNo() == rno) {
                cout << "\nFound:\n";
                bookings[i]->show();
                return;
            }
        }
        cout << "Not found.\n";
    }

    ~Hotel() {
        for (int i = 0; i < count; i++) delete bookings[i];
    }
};

int main() {
    Hotel h;
    int ch;
    int operations = 0;

    // ---- User Registration & Login System ----
    int authChoice;
    string user, pass, u, p;

    cout << "1. Register\n2. Login\nChoice: ";
    cin >> authChoice;

    if (authChoice == 1) {
        ofstream fout("users.txt", ios::app);
        cout << "New Username: ";
        cin >> user;
        cout << "New Password: ";
        cin >> pass;
        fout << user << " " << pass << endl;
        fout.close();
        cout << "Registration successful! Now login.\n";
    }

    cout << "\n--- Login ---\n";
    cout << "Username: ";
    cin >> user;
    cout << "Password: ";
    cin >> pass;

    bool found = false;
    ifstream fin("users.txt");
    while (fin >> u >> p) {
        if (u == user && p == pass) {
            found = true;
            break;
        }
    }
    fin.close();

    if (!found) {
        cout << "Invalid credentials. System closing.\n";
        return 0;
    }

    cout << "Login successful.\n";

    // ---- Session start time ----
    time_t now = time(0);
    cout << "Session started at: " << ctime(&now);

    // ---- Main controller loop ----
    do {
        cout << "\n=== HOTEL MANAGEMENT SYSTEM ===\n";
        cout << "1. Book Room\n";
        cout << "2. Show All\n";
        cout << "3. Search Room\n";
        cout << "4. Exit\n";
        cout << "Choice: ";

        // Input validation for menu
        if (!(cin >> ch)) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Enter numbers only.\n";
            continue;
        }

        switch (ch) {
            case 1: {
                // ========== INPUT VALIDATION IN MAIN ==========
                int roomChoice;
                cout << "\n1. Deluxe  2. Executive  3. Presidential\nChoice: ";
                char roomChoiceStr[10];
                cin >> roomChoiceStr;
                if (!isAllDigits(roomChoiceStr)) {
                    cout << "Invalid! Please enter numbers only.\n";
                    break;
                }
                roomChoice = atoi(roomChoiceStr);
                if (roomChoice < 1 || roomChoice > 3) {
                    cout << "Invalid choice. Please enter 1, 2, or 3.\n";
                    break;
                }

                // Validate Room Number (numbers only)
                char roomNoStr[20];
                cout << "Enter room number: ";
                cin >> roomNoStr;
                if (!isAllDigits(roomNoStr)) {
                    cout << "Invalid! Please enter numbers only for room number.\n";
                    break;
                }

                // Validate Guest Name (letters only)
                char guestName[30];
                cout << "Enter guest name (one word): ";
                cin >> guestName;
                if (!isAllLetters(guestName)) {
                    cout << "Invalid! Please enter letters only for guest name.\n";
                    break;
                }

                // Validate Phone Number (numbers only)
                char phone[15];
                cout << "Enter phone (digits only): ";
                cin >> phone;
                if (!isAllDigits(phone)) {
                    cout << "Invalid! Please enter numbers only for phone.\n";
                    break;
                }

                // Validate Number of Days (numbers only)
                char daysStr[10];
                cout << "Enter number of days: ";
                cin >> daysStr;
                if (!isAllDigits(daysStr)) {
                    cout << "Invalid! Please enter numbers only for days.\n";
                    break;
                }

                // All validation passed - feed data back to cin and call bookRoom()
                stringstream ss;
                ss << roomChoice << " " << roomNoStr << " " << guestName << " " << phone << " " << daysStr;
                
                // Save old cin buffer and replace with our validated data
                streambuf* oldCin = cin.rdbuf(ss.rdbuf());
                h.bookRoom();
                cin.rdbuf(oldCin);  // Restore original cin
                
                operations++;
                break;
            }

            case 2:
                h.showAll();
                operations++;
                break;

            case 3: {
                // Validate search room number
                char searchRnoStr[20];
                cout << "Room number: ";
                cin >> searchRnoStr;
                if (!isAllDigits(searchRnoStr)) {
                    cout << "Invalid! Please enter numbers only for room number.\n";
                    break;
                }
                // Feed validated input to searchByRoom
                stringstream ss;
                ss << searchRnoStr;
                streambuf* oldCin = cin.rdbuf(ss.rdbuf());
                h.searchByRoom();
                cin.rdbuf(oldCin);
                operations++;
                break;
            }

            case 4: {
                char confirm;
                cout << "Exit system? (y/n): ";
                cin >> confirm;
                if (confirm == 'y' || confirm == 'Y') {
                    cout << "System shutting down safely...\n";
                } else {
                    ch = 0; // cancel exit
                }
                break;
            }

            default:
                cout << "Invalid choice.\n";
        }

        cout << "\n-----------------------------\n";

    } while (ch != 4);

    // ---- Session summary ----
    cout << "Total operations this session: " << operations << endl;
    cout << "Thank you for using Hotel Management System.\n";

    return 0;
}