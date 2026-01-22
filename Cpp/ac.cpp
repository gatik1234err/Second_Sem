// Swap two variables without using a third variable

#include <iostream>
using namespace std;

int main() {
    // Method 1: Using Arithmetic Operations (+/-)
    int a = 5, b = 10;
    cout << "Method 1: Using Arithmetic Operations" << endl;
    cout << "Before: a = " << a << ", b = " << b << endl;
    
    a = a + b;
    b = a - b;
    a = a - b;
    
    cout << "After:  a = " << a << ", b = " << b << endl << endl;
    return 0;
}

