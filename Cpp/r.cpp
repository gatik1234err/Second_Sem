#include <iostream>
using namespace std;

int main() {
    int n, b, digit, i, count = 0, temp;
    long sum = 0, power;
    
    cout << "Enter number: ";
    cin >> n;
    b = n; temp = n;
    
    while(temp > 0) {
        count++;
        temp /= 10;
    }
    
    temp = n; 
    while(temp > 0) {
        digit = temp % 10;
        power = 1;
        for(i = 0; i < count; i++) {
            power *= digit; 
        }
        sum += power;
        temp /= 10;
    }
    
    if(sum == b) {
        cout << b << " is Armstrong" << endl;
    } else {
        cout << b << " nto Armstrong." << endl;
    }
    return 0;
}
