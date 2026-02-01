#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>    // for isalpha, isdigit

using namespace std;

const int MAX_BOOKINGS = 10;   // limit on number of rooms in hotel

// ---------- Safe integer input helper ----------

int getInt(const char* prompt) {
    int x;
    while (true) {
        cout << prompt;
        cin >> x;
        if (!cin.fail())
            return x;

        cout << "Invalid number. Try again.\n";
        cin.clear();
        cin.ignore(1000, '\n');
    }
}

// ---------- Validation helpers (char arrays) ----------

bool isLettersOnly(const char* s) {
    int len = strlen(s);
    if (len == 0) return false;
    for (int i = 0; i < len; i++) {
        if (!isalpha(static_cast<unsigned char>(s[i])))  // must be A-Z or a-z
            return false;
    }
    return true;
}

bool isTenDigitPhone(const char* s) {
    if (strlen(s) != 10) return false;
    for (int i = 0; i < 10; i++) {
        if (!isdigit(static_cast<unsigned char>(s[i])))  // must be digit
            return false;
    }
    return true;
}

// ---------- Base class with polymorphism ----------

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
        roomNo = getInt("Enter room number (1-100): ");
        while (roomNo < 1 || roomNo > 100) {
            cout << "Room number must be between 1 and 100.\n";
            roomNo = getInt("Enter room number (1-100): ");
        }

        // name: letters only
        do {
            cout << "Enter guest name (letters only, no spaces): ";
            cin >> guestName;
            if (!isLettersOnly(guestName))
                cout << "Invalid name. Use only A-Z or a-z, no digits/symbols.\n";
        } while (!isLettersOnly(guestName));

        // phone: exactly 10 digits
        do {
            cout << "Enter phone (exactly 10 digits): ";
            cin >> phone;
            if (!isTenDigitPhone(phone))
                cout << "Invalid phone. Must be exactly 10 digits.\n";
        } while (!isTenDigitPhone(phone));

        days = getInt("Enter number of days (>0): ");
        while (days <= 0) {
            cout << "Days must be positive.\n";
            days = getInt("Enter number of days (>0): ");
        }
    }

    virtual double getRatePerDay() const = 0;     // pure virtual
    virtual const char* getType() const = 0;      // to print type

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

    // write a simple text record to file
    void save(ofstream &fout) const {
        fout << roomNo << ' '
             << getType() << ' '
             << guestName << ' '
             << phone << ' '
             << days << ' '
             << totalCost() << '\n';
    }

    virtual ~Room() {}
};

// ---------- Derived classes ----------

class DeluxeRoom : public Room {
public:
    virtual double getRatePerDay() const { return 1000.0; }
    virtual const char* getType() const  { return "Deluxe"; }
};

class ExecutiveRoom : public Room {
public:
    virtual double getRatePerDay() const { return 1500.0; }
    virtual const char* getType() const  { return "Executive"; }
};

class PresidentialRoom : public Room {
public:
    virtual double getRatePerDay() const { return 2500.0; }
    virtual const char* getType() const  { return "Presidential"; }
};

// ---------- Hotel class with limit + file handling ----------

class Hotel {
    Room* bookings[MAX_BOOKINGS];
    int count;

public:
    Hotel() {
        count = 0;
        for (int i = 0; i < MAX_BOOKINGS; i++) bookings[i] = NULL;
    }

    bool roomNumberExists(int rno) {
        for (int i = 0; i < count; i++) {
            if (bookings[i]->getRoomNo() == rno) return true;
        }
        return false;
    }

    void bookRoom() {
        if (count >= MAX_BOOKINGS) {
            cout << "Hotel full (" << MAX_BOOKINGS
                 << " rooms). Cannot add more bookings.\n";
            return;
        }

        cout << "\nSelect room type:\n";
        cout << "1. Deluxe\n";
        cout << "2. Executive\n";
        cout << "3. Presidential\n";
        int choice = getInt("Enter choice: ");

        Room* r = NULL;
        if (choice == 1)      r = new DeluxeRoom;
        else if (choice == 2) r = new ExecutiveRoom;
        else if (choice == 3) r = new PresidentialRoom;
        else {
            cout << "Invalid type.\n";
            return;
        }

        r->inputCommon();

        if (roomNumberExists(r->getRoomNo())) {
            cout << "Error: This room number is already booked.\n";
            delete r;
            return;
        }

        bookings[count] = r;
        count++;

        cout << "Room booked successfully.\n";
    }

    void showAll() {
        if (count == 0) {
            cout << "No bookings yet.\n";
            return;
        }
        for (int i = 0; i < count; i++) {
            cout << "\n-----------------------\n";
            bookings[i]->show();
        }
    }

    void searchByRoom() {
        if (count == 0) {
            cout << "No bookings.\n";
            return;
        }
        int rno = getInt("Enter room number to search: ");

        for (int i = 0; i < count; i++) {
            if (bookings[i]->getRoomNo() == rno) {
                cout << "\nBooking found:\n";
                bookings[i]->show();
                return;
            }
        }
        cout << "No booking for this room.\n";
    }

    void saveToFile() {
        ofstream fout("hotel.txt");
        if (!fout) {
            cout << "Error opening file for writing.\n";
            return;
        }
        fout << "RoomNo Type Name Phone Days TotalCost\n";
        for (int i = 0; i < count; i++) {
            bookings[i]->save(fout);
        }
        fout.close();
        cout << "Bookings saved to hotel.txt\n";
    }

    void showFileContents() {
        ifstream fin("hotel.txt");
        if (!fin) {
            cout << "No file found. Save first.\n";
            return;
        }
        cout << "\n--- Contents of hotel.txt ---\n";
        char ch;
        while (fin.get(ch)) {
            cout << ch;
        }
        fin.close();
        cout << "\n-----------------------------\n";
    }

    ~Hotel() {
        for (int i = 0; i < count; i++) {
            delete bookings[i];
        }
    }
};

// ---------- main ----------

int main() {
    Hotel h;
    int ch;

    do {
        cout << "\n===== HOTEL MANAGEMENT (INHERITANCE + POLYMORPHISM + FILE) =====\n";
        cout << "1. Book Room\n";
        cout << "2. Show All Bookings\n";
        cout << "3. Search by Room Number\n";
        cout << "4. Save Bookings to File\n";
        cout << "5. Show File Contents\n";
        cout << "6. Exit\n";
        ch = getInt("Enter choice: ");

        switch (ch) {
            case 1: h.bookRoom(); break;
            case 2: h.showAll(); break;
            case 3: h.searchByRoom(); break;
            case 4: h.saveToFile(); break;
            case 5: h.showFileContents(); break;
            case 6: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (ch != 6);

    return 0;
}
