# Hotel Management System - Complete Documentation

## Overview
A C++ hotel management system featuring user authentication, room booking with three room types, input validation, and session tracking. Built using object-oriented programming principles.

---

## Quick Start

```bash
# Compile
g++ hotell.cpp -o hotell

# Run
./hotell
```

---

## Program Structure

### Saad's Part (Lines 1-57)
**Headers, Room Class, DeluxeRoom Class**

### Anjali's Part (Lines 59-78)
**ExecutiveRoom, PresidentialRoom Classes**

### Gatik's Part (Lines 80-146)
**Hotel Class (bookRoom, showAll, searchByRoom)**

### Kushal's Part (Lines 149-251)
**Validation, Authentication, Main Function**

---

## Detailed Line-by-Line Explanation

### === SAAD'S PART ===

#### Line 1-7: Include Headers
```cpp
#include <iostream>
#include <ctime>
#include <cstring>
#include <cstdlib>
#include <sstream>
#include <fstream>
using namespace std;
```
| Header | Purpose |
|--------|---------|
| `<iostream>` | Console input/output (cin, cout) |
| `<ctime>` | Time functions (time(), ctime()) |
| `<cstring>` | C-string functions (strlen) |
| `<cstdlib>` | General utilities (atoi) |
| `<sstream>` | String stream for input redirection |
| `<fstream>` | File operations (ifstream, ofstream) |

---

#### Lines 9-41: Room Class (Abstract Base Class)

##### Lines 10-15: Protected Data Members
```cpp
protected:
    int roomNo;          // Room identification number
    char guestName[30];  // Guest name (max 29 chars + null)
    char phone[15];      // Phone number (max 14 chars + null)
    int days;            // Number of days for stay
```
- **Protected**: Accessible by derived classes, hidden from outside
- **Character Arrays**: Fixed-size buffers for string storage

##### Lines 17-29: Constructor
```cpp
public:
    Room() {
        roomNo = 0;
        guestName[0] = '\0';  // Empty string
        phone[0] = '\0';       // Empty string
        days = 0;
    }
```
- Initializes all members to default/empty values
- `'\0'` is null terminator making strings empty

##### Lines 31-42: inputCommon() Method
```cpp
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
```
- Collects guest booking information
- `cin >>` reads from standard input

##### Lines 44-46: Pure Virtual Functions
```cpp
    virtual double getRatePerDay() const = 0;
    virtual const char* getType() const = 0;
```
- **Pure virtual**: Must be implemented by derived classes
- **`const`**: Promises not to modify object state
- Makes `Room` an abstract class (cannot be instantiated)

##### Lines 48-50: totalCost() Method
```cpp
    double totalCost() const {
        return days * getRatePerDay();
    }
```
- Calculates total bill: `days × daily rate`
- Polymorphic call to derived class implementation

##### Lines 52-53: Getter Method
```cpp
    int getRoomNo() const { return roomNo; }
```
- Simple getter for room number
- Enables searching by room number

##### Lines 55-63: show() Method
```cpp
    void show() const {
        cout << "Room No   : " << roomNo << "\n";
        cout << "Type      : " << getType() << "\n";
        cout << "Guest     : " << guestName << "\n";
        cout << "Phone     : " << phone << "\n";
        cout << "Days      : " << days << "\n";
        cout << "Rate/Day  : " << getRatePerDay() << "\n";
        cout << "Total Bill: " << totalCost() << "\n";
    }
```
- Displays complete booking information
- Uses polymorphic calls for rate and type

##### Lines 65-66: Virtual Destructor
```cpp
    virtual ~Room() {}
```
- Enables proper cleanup of derived objects through base pointers
- Required when polymorphism is used

---

#### Lines 68-78: DeluxeRoom Class
```cpp
class DeluxeRoom : public Room {
public:
    double getRatePerDay() const override {
        return 1000.0;  // $1000 per day
    }
    const char* getType() const override {
        return "Deluxe";
    }
};
```
- Inherits from `Room`
- **`override`**: Explicitly states overriding virtual function
- Rate: **$1000/day**

---

### === ANJALI'S PART ===

#### Lines 80-90: ExecutiveRoom Class
```cpp
class ExecutiveRoom : public Room {
public:
    double getRatePerDay() const override {
        return 1500.0;  // $1500 per day
    }
    const char* getType() const override {
        return "Executive";
    }
};
```
- Second room tier
- Rate: **$1500/day**

---

#### Lines 92-102: PresidentialRoom Class
```cpp
class PresidentialRoom : public Room {
public:
    double getRatePerDay() const override {
        return 2500.0;  // $2500 per day
    }
    const char* getType() const override {
        return "Presidential";
    }
};
```
- Highest tier room
- Rate: **$2500/day**

---

### === GATIK'S PART ===

#### Lines 104-146: Hotel Class

##### Lines 105-107: Data Members
```cpp
    Room* bookings[100];  // Array of 100 room pointers
    int count;            // Tracks current bookings
```
- Polymorphic storage: base pointer holds derived objects
- Maximum 100 bookings

##### Lines 109-114: Constructor
```cpp
public:
    Hotel() : count(0) {
        for (int i = 0; i < 100; i++) bookings[i] = nullptr;
    }
```
- Member initializer list: `count(0)`
- Loop initializes all pointers to `nullptr`

##### Lines 116-136: bookRoom() Method
```cpp
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
```
| Step | Action |
|------|--------|
| 1 | Check if hotel is full (100 bookings max) |
| 2 | Prompt for room type selection |
| 3 | Create appropriate Room object dynamically |
| 4 | Call inputCommon() to get guest details |
| 5 | Store in array and increment count |

##### Lines 138-148: showAll() Method
```cpp
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
```
- Displays all bookings with 1-based numbering
- Polymorphic `show()` call displays correct room type

##### Lines 150-166: searchByRoom() Method
```cpp
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
```
- Linear search through all bookings
- Returns first match found

##### Lines 168-171: Destructor
```cpp
    ~Hotel() {
        for (int i = 0; i < count; i++) delete bookings[i];
    }
```
- Frees dynamically allocated memory
- Prevents memory leaks

---

### === KUSHAL'S PART ===

#### Lines 174-181: Validation Functions

##### isAllDigits()
```cpp
bool isAllDigits(const char* s) {
    for (int i = 0; s[i]; i++) 
        if (s[i] < '0' || s[i] > '9') return false;
    return strlen(s) > 0;
}
```
- Returns `true` if ALL characters are digits 0-9
- Returns `false` if empty or contains non-digits
- `s[i]` is truthy until null terminator

##### isAllLetters()
```cpp
bool isAllLetters(const char* s) {
    for (int i = 0; s[i]; i++) 
        if (!isalpha(s[i])) return false;
    return strlen(s) > 0;
}
```
- Returns `true` if ALL characters are letters A-Z/a-z
- Returns `false` if empty or contains non-letters
- `isalpha()` checks for alphabetic characters

---

#### Lines 183-189: readValidated()
```cpp
bool readValidated(const char* prompt, char* buf, int size, 
                   bool (*check)(const char*), const char* err) {
    cout << prompt;
    cin >> buf;
    if (!check(buf)) { 
        cout << err << "\n"; 
        return false; 
    }
    return true;
}
```
| Parameter | Description |
|-----------|-------------|
| `prompt` | Message to display |
| `buf` | Buffer to store input |
| `size` | Maximum buffer size |
| `check` | Function pointer to validation |
| `err` | Error message on invalid input |

- Reads input and validates using callback function
- Returns `true` if valid, `false` otherwise

---

#### Lines 191-251: main() Function

##### Lines 192-194: Variable Declarations
```cpp
    Hotel h;
    int ch, operations = 0;
    string user, pass, u, p;
    int authChoice;
```
- `h`: Hotel instance
- `ch`: Menu choice
- `operations`: Tracks number of actions
- `user, pass`: Input username/password
- `u, p`: Read username/password from file

---

##### Lines 197-207: Registration
```cpp
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
```
- `ios::app`: Append mode (doesn't overwrite)
- Saves credentials to `users.txt` in format: `username password`

---

##### Lines 209-221: Login Verification
```cpp
    cout << "\n--- Login ---\n";
    cout << "Username: "; cin >> user;
    cout << "Password: "; cin >> pass;

    bool found = false;
    ifstream fin("users.txt");
    while (fin >> u >> p) 
        if (u == user && p == pass) { found = true; break; }
    fin.close();

    if (!found) { 
        cout << "Invalid credentials. System closing.\n"; 
        return 0; 
    }
    cout << "Login successful.\n";
```
- Reads file line by line
- Checks for exact username/password match
- Exits if credentials invalid

---

##### Lines 223-225: Session Start Time
```cpp
    time_t now = time(0);
    cout << "Session started at: " << ctime(&now);
```
- `time(0)`: Gets current time in seconds since epoch (Jan 1, 1970)
- `ctime()`: Converts to human-readable string

---

##### Lines 227-245: Main Menu Loop
```cpp
    do {
        cout << "\n=== HOTEL MANAGEMENT SYSTEM ===\n"
             << "1. Book Room\n2. Show All\n3. Search Room\n4. Exit\nChoice: ";

        if (!(cin >> ch)) { 
            cin.clear(); 
            cin.ignore(1000, '\n'); 
            cout << "Enter numbers only.\n"; 
            continue; 
        }
```
- `do-while`: Executes at least once
- `cin.clear()`: Clears error flags on invalid input
- `cin.ignore()`: Discards up to 1000 characters or until newline

---

##### Lines 247-250: Case 1 - Book Room
```cpp
        case 1: {
            char rc[10], rno[20], name[30], phone[15], days[10];

            cout << "\n1. Deluxe  2. Executive  3. Presidential\nChoice: ";
            cin >> rc;
            if (!isAllDigits(rc) || atoi(rc) < 1 || atoi(rc) > 3) { 
                cout << "Invalid choice. Please enter 1, 2, or 3.\n"; 
                break; 
            }
```
- `atoi()`: Converts string to integer
- Validates choice is 1, 2, or 3

---

##### Lines 251-256: Input Validation Chain
```cpp
            if (!readValidated("Enter room number: ",   rno,  20, isAllDigits,  
                "Invalid! Please enter numbers only for room number."))  break;
            if (!readValidated("Enter guest name (one word): ", name, 30, isAllLetters, 
                "Invalid! Please enter letters only for guest name.")) break;
            if (!readValidated("Enter phone (digits only): ",  phone, 15, isAllDigits,  
                "Invalid! Please enter numbers only for phone."))     break;
            if (!readValidated("Enter number of days: ",       days, 10, isAllDigits,  
                "Invalid! Please enter numbers only for days."))      break;
```
- Each field validated with appropriate function
- `break` exits case on any validation failure

---

##### Lines 258-263: Input Redirection Trick
```cpp
            stringstream ss;
            ss << rc << " " << rno << " " << name << " " << phone << " " << days;
            streambuf* old = cin.rdbuf(ss.rdbuf());
            h.bookRoom();
            cin.rdbuf(old);
```
| Step | Action |
|------|--------|
| 1 | Create stringstream with validated inputs |
| 2 | Save original cin buffer pointer |
| 3 | Redirect cin to stringstream |
| 4 | Call bookRoom() which uses cin |
| 5 | Restore original cin buffer |

---

##### Lines 265-270: Case 2 & 3
```cpp
            operations++;
            break;
        }
        case 2:
            h.showAll();
            operations++;
            break;

        case 3: {
            char rno[20];
            if (!readValidated("Room number: ", rno, 20, isAllDigits, 
                "Invalid! Please enter numbers only for room number.")) break;

            stringstream ss;
            ss << rno;
            streambuf* old = cin.rdbuf(ss.rdbuf());
            h.searchByRoom();
            cin.rdbuf(old);
            operations++;
            break;
        }
```
- Case 2: Show all bookings
- Case 3: Search by room number with validation
- Both increment operation counter

---

##### Lines 272-281: Case 4 - Exit
```cpp
        case 4: {
            char c;
            cout << "Exit system? (y/n): ";
            cin >> c;
            if (c != 'y' && c != 'Y') ch = 0;
            else cout << "System shutting down safely...\n";
            break;
        }
```
- Confirmation before exit
- If 'y' or 'Y': exits (ch=4)
- Otherwise: continues loop (ch=0)

---

##### Lines 283-285: Loop End
```cpp
        default:
            cout << "Invalid choice.\n";
    }
    cout << "\n-----------------------------\n";

} while (ch != 4);
```
- Default case for invalid menu choices
- Loop continues until ch equals 4 (exit)

---

##### Lines 287-290: Session Summary
```cpp
    cout << "Total operations this session: " << operations << "\n"
         << "Thank you for using Hotel Management System.\n";
    return 0;
}
```
- Displays total operations performed
- Returns 0 (success) to operating system

---

## Room Types & Rates

| Class | Rate/Day | Room Type String |
|-------|----------|------------------|
| DeluxeRoom | $1000 | "Deluxe" |
| ExecutiveRoom | $1500 | "Executive" |
| PresidentialRoom | $2500 | "Presidential" |

---

## OOP Concepts Used

| Concept | Implementation |
|---------|---------------|
| **Abstraction** | Abstract `Room` class with pure virtual functions |
| **Inheritance** | Three room types inherit from `Room` |
| **Polymorphism** | Virtual functions overridden in derived classes |
| **Encapsulation** | Data members protected, accessed via methods |
| **Dynamic Binding** | Runtime determination of actual object type |

---

## File Format

**users.txt**
```
username1 password1
username2 password2
username3 password3
```

- One user per line
- Space-separated credentials
- No encryption (for educational purposes)

---

## Validation Rules

| Field | Valid Characters | Validation Function |
|-------|-----------------|-------------------|
| Room Number | 0-9 | `isAllDigits()` |
| Guest Name | A-Z, a-z | `isAllLetters()` |
| Phone | 0-9 | `isAllDigits()` |
| Days | 0-9 | `isAllDigits()` |
| Menu Choice | 1, 2, 3, 4 | Manual check |

---

## Memory Management

| Allocation | Location | Deallocation |
|------------|----------|--------------|
| `new DeluxeRoom()` | bookRoom() | Hotel destructor |
| `new ExecutiveRoom()` | bookRoom() | Hotel destructor |
| `new PresidentialRoom()` | bookRoom() | Hotel destructor |

- All dynamically allocated objects are freed in destructor
- No memory leaks

---

## Authentication Flow

```
┌─────────────────┐
│ 1. Register?    │──── YES ──► [Save to users.txt]
 │ 2. Login?      │              │
 └───────┬────────┘              │
         │ NO                   │
         ▼                      │
    [Login Screen] ◄────────────┘
         │
    ┌────┴────┐
    │ Valid?  │
    └────┬────┘
         │
    NO   │   YES
    │     │
    ▼     ▼
  EXIT   ▼
      [Main Menu]
```

---

## Contributors

| Person | Contribution |
|--------|-------------|
| **Saad** | Headers, Room class, DeluxeRoom class |
| **Anjali** | ExecutiveRoom, PresidentialRoom classes |
| **Gatik** | Hotel class, booking management |
| **Kushal** | Validation, authentication, main loop |

---

## Program Output Example

```
1. Register
2. Login
Choice: 1
New Username: john
New Password: secret
Registration successful! Now login.

--- Login ---
Username: john
Password: secret
Login successful.
Session started at: Wed Dec 11 10:30:00 2024

=== HOTEL MANAGEMENT SYSTEM ===
1. Book Room
2. Show All
3. Search Room
4. Exit
Choice: 1

1. Deluxe  2. Executive  3. Presidential
Choice: 2
Enter room number: 101
Enter guest name (one word): JohnSmith
Enter phone (digits only): 1234567890
Enter number of days: 5
Booked.

-----------------------------

=== HOTEL MANAGEMENT SYSTEM ===
1. Book Room
2. Show All
3. Search Room
4. Exit
Choice: 4
Exit system? (y/n): y
System shutting down safely...
Total operations this session: 1
Thank you for using Hotel Management System.
```

