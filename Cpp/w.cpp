#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

int add(int a, int b) {
    return a + b;
}

void greet() {
    cout << "Welcome to cpp Functions\n";
}

bool isEven(int n) {
    return (n % 2 == 0);
}

void callByValue(int x) {
    x = 100;
    cout << "Inside of call by Value " << x << endl;
}

void callByReference(int &x) {
    x = 200;
}

void callByPointer(int *x) {
    *x = 300;
    cout << "Call by Pointer " << *x << endl;
}  // Added missing }

int main() {
    greet();  // Call your dead functions or burn 'em
    cout << add(5, 3) << endl;
    cout << (isEven(4) ? "Even" : "Odd") << endl;

    cout << "\nCall By Value\n";
    int a = 10;
    callByValue(a);
    cout << "After call by Value " << a << endl;  // Still 10

    cout << "\nCall By Reference\n";
    int b = 20;
    callByReference(b);
    cout << "After call by Reference " << b << endl;  // Now 200

    cout << "\nCall By Pointer\n";
    int c = 30;
    callByPointer(&c);
    cout << "After call by Pointer " << c << endl;  // Now 300

    return 0;
}