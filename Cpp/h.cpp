#include <iostream>


using namespace std;

int main() {
    int a, b, c;

    cout << "Enter first integer: ";
    cin >> a;
    cout << "Enter second integer: ";
    cin >> b;
    cout << "Enter third integer: ";
    cin >> c;

    int greatest = std::max(a, std::max(b, c));

    cout << "Greatest: " << greatest << endl;

    return 0;
}
