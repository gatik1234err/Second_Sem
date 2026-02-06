// saad's part begins
#include <iostream>
#include <ctime>
#include <cstring>
#include <cstdlib>
#include <sstream>
#include <fstream>
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
// saad's part ends
//Anjali's part begins

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

        // anjali's part ends here


        //gatik's part begins
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
//gatik's part ends here



// ----------------ksuhals part below--------------------------


bool isAllDigits(const char* s) {
    for (int i = 0; s[i]; i++) if (s[i] < '0' || s[i] > '9') return false;
    return strlen(s) > 0;
}

bool isAllLetters(const char* s) {
    for (int i = 0; s[i]; i++) if (!isalpha(s[i])) return false;
    return strlen(s) > 0;
}

// Reads input, validates with the given check function, prints error on fail. Returns true if valid.
bool readValidated(const char* prompt, char* buf, int size, bool (*check)(const char*), const char* err) {
    cout << prompt;
    cin >> buf;
    if (!check(buf)) { cout << err << "\n"; return false; }
    return true;
}

int main() {
    Hotel h;
    int ch, operations = 0;
    string user, pass, u, p;
    int authChoice;

    // ---- Registration & Login ----
    cout << "1. Register\n2. Login\nChoice: ";
    cin >> authChoice;

    if (authChoice == 1) {
        ofstream fout("users.txt", ios::app);
        cout << "New Username: "; cin >> user;
        cout << "New Password: "; cin >> pass;
        fout << user << " " << pass << endl;
        fout.close();
        cout << "Registration successful! Now login.\n";
    }

    cout << "\n--- Login ---\n";
    cout << "Username: "; cin >> user;
    cout << "Password: "; cin >> pass;

    bool found = false;
    ifstream fin("users.txt");
    while (fin >> u >> p) if (u == user && p == pass) { found = true; break; }
    fin.close();

    if (!found) { cout << "Invalid credentials. System closing.\n"; return 0; }
    cout << "Login successful.\n";

    time_t now = time(0);
    cout << "Session started at: " << ctime(&now);

    // ---- Main Loop ----
    do {
        cout << "\n=== HOTEL MANAGEMENT SYSTEM ===\n"
             << "1. Book Room\n2. Show All\n3. Search Room\n4. Exit\nChoice: ";

        if (!(cin >> ch)) { cin.clear(); cin.ignore(1000, '\n'); cout << "Enter numbers only.\n"; continue; }

        switch (ch) {
            case 1: {
                char rc[10], rno[20], name[30], phone[15], days[10];

                cout << "\n1. Deluxe  2. Executive  3. Presidential\nChoice: ";
                cin >> rc;
                if (!isAllDigits(rc) || atoi(rc) < 1 || atoi(rc) > 3) { cout << "Invalid choice. Please enter 1, 2, or 3.\n"; break; }
                if (!readValidated("Enter room number: ",   rno,  20, isAllDigits,  "Invalid! Please enter numbers only for room number."))  break;
                if (!readValidated("Enter guest name (one word): ", name, 30, isAllLetters, "Invalid! Please enter letters only for guest name.")) break;
                if (!readValidated("Enter phone (digits only): ",  phone, 15, isAllDigits,  "Invalid! Please enter numbers only for phone."))     break;
                if (!readValidated("Enter number of days: ",       days, 10, isAllDigits,  "Invalid! Please enter numbers only for days."))      break;

                stringstream ss;
                ss << rc << " " << rno << " " << name << " " << phone << " " << days;
                streambuf* old = cin.rdbuf(ss.rdbuf());
                h.bookRoom();
                cin.rdbuf(old);
                operations++;
                break;
            }
            case 2:
                h.showAll();
                operations++;
                break;

            case 3: {
                char rno[20];
                if (!readValidated("Room number: ", rno, 20, isAllDigits, "Invalid! Please enter numbers only for room number.")) break;

                stringstream ss;
                ss << rno;
                streambuf* old = cin.rdbuf(ss.rdbuf());
                h.searchByRoom();
                cin.rdbuf(old);
                operations++;
                break;
            }
            case 4: {
                char c;
                cout << "Exit system? (y/n): ";
                cin >> c;
                if (c != 'y' && c != 'Y') ch = 0;
                else cout << "System shutting down safely...\n";
                break;
            }
            default:
                cout << "Invalid choice.\n";
        }
        cout << "\n-----------------------------\n";

    } while (ch != 4);

    cout << "Total operations this session: " << operations << "\n"
         << "Thank you for using Hotel Management System.\n";
    return 0;
}
// ---------------------------------------------------------------