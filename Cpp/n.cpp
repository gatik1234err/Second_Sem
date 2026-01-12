#include <iostream>
using namespace std;

int main() {
    int num ;
    int rev = 0;
    cout << "Enter Num" << endl;
    cin >> num;
    while (num != 0) {
        int digit = num % 10;
        rev = rev * 10 + digit;
        num /= 10;
    }
    cout << "Reverse" << rev << endl;
    return 0;
}
