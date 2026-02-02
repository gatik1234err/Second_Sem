# Hotel Booking System - Line-by-Line Explanation

## Overview
This C++ program implements a simple hotel room booking system with three types of rooms (Deluxe, Executive, Presidential). It uses object-oriented programming principles including inheritance, polymorphism, and abstract classes.

---

## Code Explanation

### 1. Include Directive and Namespace
```cpp
#include <iostream>
```
**Purpose:** Includes the input/output stream library, which provides `cout` for output and `cin` for input operations.

```cpp
using namespace std;
```
**Purpose:** Allows using standard library components (like `cout`, `cin`, `string`) without prefixing them with `std::`. This is a convenience directive but can be avoided in larger projects to prevent namespace pollution.

---

## 2. Room Class (Abstract Base Class)

### Class Declaration
```cpp
class Room {
protected:
    int roomNo;
    char guestName[30];
    char phone[15];
    int days;
```
**Purpose:** Defines an abstract base class for all room types.

- `protected:` - Access modifier allowing derived classes to access these members directly
- `int roomNo;` - Stores the room number (integer)
- `char guestName[30];` - Character array to store guest name (max 29 chars + null terminator)
- `char phone[15];` - Character array for phone number (max 14 chars + null terminator)
- `int days;` - Number of days the room is booked for

### Public Member Functions
```cpp
public:
    Room() {
        roomNo = 0;
        guestName[0] = '\0';
        phone[0] = '\0';
        days = 0;
    }
```
**Purpose:** Default constructor that initializes all member variables to default values.

- `Room()` - Constructor with same name as class, no parameters
- `roomNo = 0;` - Sets room number to 0 (invalid/empty state)
- `guestName[0] = '\0';` - Sets first character to null terminator, making it an empty string
- `phone[0] = '\0';` - Sets first character to null terminator, making it an empty string
- `days = 0;` - Sets days to 0 (no booking)

### Input Method
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
**Purpose:** Collects common booking information from user.

- `void inputCommon()` - Returns nothing, collects user input
- `cout << "Enter room number: ";` - Displays prompt message
- `cin >> roomNo;` - Reads integer input into roomNo
- `cin >> guestName;` - Reads string input into guestName array (one word only)
- `cin >> phone;` - Reads string input into phone array
- `cin >> days;` - Reads integer input into days

### Pure Virtual Functions
```cpp
    virtual double getRatePerDay() const = 0;
    virtual const char* getType() const = 0;
```
**Purpose:** Declares pure virtual functions that must be implemented by derived classes.

- `virtual` - Allows function overriding in derived classes
- `double getRatePerDay() const = 0;` - Must return the daily rate (pure virtual)
- `const char* getType() const = 0;` - Must return room type name (pure virtual)
- `const` - Promises not to modify member variables

### Cost Calculation
```cpp
    double totalCost() const {
        return days * getRatePerDay();
    }
```
**Purpose:** Calculates total booking cost.

- `double totalCost() const` - Returns double, doesn't modify object
- `days * getRatePerDay();` - Multiplies number of days by daily rate (polymorphic call)

### Getter Method
```cpp
    int getRoomNo() const { return roomNo; }
```
**Purpose:** Provides read-only access to room number.

- `int getRoomNo() const` - Getter method, returns room number
- `return roomNo;` - Returns the private/protected member value

### Display Method
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
**Purpose:** Displays all booking information in formatted manner.

- `void show() const` - Display function, doesn't modify object
- Each `cout` statement outputs a label and corresponding value
- `getType()` and `getRatePerDay()` are called polymorphically

### Virtual Destructor
```cpp
    virtual ~Room() {}
```
**Purpose:** Virtual destructor ensures proper cleanup of derived class objects through base class pointers.

- `virtual ~Room() {}` - Empty virtual destructor for polymorphic deletion

---

## 3. Derived Room Classes

### DeluxeRoom Class
```cpp
class DeluxeRoom : public Room {
public:
    double getRatePerDay() const override {
        return 1000.0;
    }
    const char* getType() const override {
        return "Deluxe";
    }
};
```
**Purpose:** Concrete implementation of Room for deluxe rooms.

- `class DeluxeRoom : public Room` - Inherits from Room base class
- `override` keyword - Explicitly states these functions override base class virtual functions
- `return 1000.0;` - Deluxe room costs $1000 per day
- `return "Deluxe";` - Returns room type as string literal

### ExecutiveRoom Class
```cpp
class ExecutiveRoom : public Room {
public:
    double getRatePerDay() const override {
        return 1500.0;
    }
    const char* getType() const override {
        return "Executive";
    }
};
```
**Purpose:** Concrete implementation for executive rooms.

- Same structure as DeluxeRoom but returns different values
- `return 1500.0;` - Executive room costs $1500 per day
- `return "Executive";` - Returns room type name

### PresidentialRoom Class
```cpp
class PresidentialRoom : public Room {
public:
    double getRatePerDay() const override {
        return 2500.0;
    }
    const char* getType() const override {
        return "Presidential";
    }
};
```
**Purpose:** Concrete implementation for presidential suite rooms.

- Highest tier room type
- `return 2500.0;` - Presidential room costs $2500 per day
- `return "Presidential";` - Returns room type name

---

## 4. Hotel Class (Manager Class)

### Class Declaration and Members
```cpp
class Hotel {
    Room* bookings[100];
    int count;
```
**Purpose:** Manages all room bookings in the hotel.

- `Room* bookings[100];` - Array of 100 pointers to Room objects (polymorphic storage)
- `int count;` - Tracks number of current bookings

### Constructor
```cpp
public:
    Hotel() : count(0) {
        for (int i = 0; i < 100; i++) bookings[i] = nullptr;
    }
```
**Purpose:** Initializes hotel with empty bookings.

- `Hotel() : count(0)` - Member initializer list sets count to 0
- `for (int i = 0; i < 100; i++)` - Loop from 0 to 99
- `bookings[i] = nullptr;` - Initialize all pointers to null (no booking)

### Book Room Method
```cpp
    void bookRoom() {
        if (count >= 100) {
            cout << "Hotel full.\n";
            return;
        }
```
**Purpose:** Creates a new room booking.

- `if (count >= 100)` - Check if hotel is at capacity
- `cout << "Hotel full.\n";` - Display full message
- `return;` - Exit function early if full

```cpp
        int choice;
        cout << "\n1. Deluxe  2. Executive  3. Presidential\nChoice: ";
        cin >> choice;
```
**Purpose:** Gets room type selection from user.

- `int choice;` - Variable to store user selection
- Displays room types with numbers
- `cin >> choice;` - Reads user's choice

```cpp
        Room* r = nullptr;
        if (choice == 1) r = new DeluxeRoom();
        else if (choice == 2) r = new ExecutiveRoom();
        else if (choice == 3) r = new PresidentialRoom();
        else {
            cout << "Invalid.\n";
            return;
        }
```
**Purpose:** Creates appropriate room object based on choice.

- `Room* r = nullptr;` - Declare pointer, initialize to null
- `new DeluxeRoom();` - Dynamically allocate DeluxeRoom object
- `new ExecutiveRoom();` - Dynamically allocate ExecutiveRoom object
- `new PresidentialRoom();` - Dynamically allocate PresidentialRoom object
- If invalid choice, show error and return

```cpp
        r->inputCommon();
        bookings[count++] = r;
        cout << "Booked.\n";
    }
```
**Purpose:** Finalizes the booking.

- `r->inputCommon();` - Call input function on new room object
- `bookings[count++] = r;` - Store pointer in array, increment count
- `cout << "Booked.\n";` - Confirm booking success

### Show All Bookings Method
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
**Purpose:** Displays all current bookings.

- `if (count == 0)` - Check if there are any bookings
- `cout << "No bookings.\n";` - Message if empty
- `for (int i = 0; i < count; i++)` - Loop through all bookings
- `cout << "\n--- Booking " << (i+1) << " ---\n";` - Display booking number (1-indexed)
- `bookings[i]->show();` - Call show method on each booking (polymorphic call)

### Search by Room Number Method
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
**Purpose:** Finds and displays a specific booking by room number.

- `if (count == 0)` - Check if hotel has any bookings
- `int rno;` - Variable to store room number to search
- `cout << "Room number: ";` - Prompt user
- `cin >> rno;` - Read room number
- `for (int i = 0; i < count; i++)` - Loop through all bookings
- `bookings[i]->getRoomNo() == rno` - Compare room numbers
- `cout << "\nFound:\n";` - Success message
- `return;` - Exit after finding match
- `cout << "Not found.\n";` - Message if no match found

### Destructor
```cpp
    ~Hotel() {
        for (int i = 0; i < count; i++) delete bookings[i];
    }
```
**Purpose:** Cleans up dynamically allocated memory when Hotel object is destroyed.

- `~Hotel()` - Destructor called automatically
- `for (int i = 0; i < count; i++)` - Loop through all bookings
- `delete bookings[i];` - Free dynamically allocated Room objects

---

## 5. Main Function

### Declaration and Hotel Object
```cpp
int main() {
    Hotel h;
    int ch;
```
**Purpose:** Entry point of the program and main loop.

- `int main()` - Program execution starts here
- `Hotel h;` - Create Hotel object instance
- `int ch;` - Variable to store menu choice

### Menu Loop
```cpp
    do {
        cout << "\n=== HOTEL ===\n";  
        cout << "1. Book Room\n";     
        cout << "2. Show All\n";
        cout << "3. Search Room\n";
        cout << "4. Exit\n";
        cout << "Choice: ";
        cin >> ch;
```
**Purpose:** Displays menu and gets user choice.

- `do {` - Start do-while loop (runs at least once)
- Displays menu options with numbers
- `cout << "Choice: ";` - Prompt for input
- `cin >> ch;` - Read user's menu choice

### Switch Statement
```cpp
        switch (ch) {
            case 1: h.bookRoom(); break;
            case 2: h.showAll(); break;
            case 3: h.searchByRoom(); break;
            case 4: cout << "Bye.\n"; break;
            default: cout << "Wrong.\n";
        }
    } while (ch != 4);
```
**Purpose:** Routes program flow based on user choice.

- `switch (ch)` - Evaluate integer variable
- `case 1:` - If ch equals 1
- `h.bookRoom();` - Call bookRoom method on hotel object
- `break;` - Exit switch statement
- `case 2:` - If ch equals 2
- `h.showAll();` - Call showAll method
- `case 3:` - If ch equals 3
- `h.searchByRoom();` - Call searchByRoom method
- `case 4:` - If ch equals 4
- `cout << "Bye.\n";` - Exit message
- `default:` - For any other value
- `cout << "Wrong.\n";` - Invalid choice message
- `} while (ch != 4);` - Continue loop until user chooses exit

### Return Statement
```cpp
    return 0;
}
```
**Purpose:** Indicates successful program termination.

- `return 0;` - Returns 0 to operating system (convention for success)
- `}` - End of main function

---

## Key Concepts Used

1. **Inheritance**: DeluxeRoom, ExecutiveRoom, and PresidentialRoom inherit from Room
2. **Polymorphism**: Virtual functions allow correct method call based on actual object type
3. **Abstraction**: Room class is abstract with pure virtual functions
4. **Dynamic Memory**: `new` and `delete` for allocating room objects
5. **Encapsulation**: Data members are protected, accessed through methods
6. **Pointers**: Array of base class pointers to store derived objects

---

## Room Rates

| Room Type | Rate Per Day |
|-----------|-------------|
| Deluxe | $1000 |
| Executive | $1500 |
| Presidential | $2500 |

---

## Compiling and Running

```bash
# Compile
g++ hotell.cpp -o hotell

# Run
./hotell
```

---

## Program Flow

1. Hotel object created
2. Menu loop starts
3. User selects option:
   - **Book Room**: Prompts for room type and guest details
   - **Show All**: Displays all current bookings
   - **Search Room**: Finds booking by room number
   - **Exit**: Terminates program
4. Loop continues until Exit option chosen
5. Hotel destructor cleans up allocated memory

