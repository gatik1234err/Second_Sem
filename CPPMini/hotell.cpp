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
    do {
        cout << "\n=== HOTEL ===\n";  
        cout << "1. Book Room\n";     
        cout << "2. Show All\n";
        cout << "3. Search Room\n";
        cout << "4. Exit\n";
        cout << "Choice: ";
        cin >> ch;
        switch (ch) {
            case 1: h.bookRoom(); break;
            case 2: h.showAll(); break;
            case 3: h.searchByRoom(); break;
            case 4: cout << "Bye.\n"; break;
            default: cout << "Wrong.\n";
        }
    } while (ch != 4);
    return 0;
}

