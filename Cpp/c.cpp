#include <iostream>
#include <algorithm>  // std::max or GTFO [web:22][web:3]
#include <string>     // For string literals, you forgetful hack [web:49]

using namespace std;

int main() {
    int a, b;

    cout << "Enter first integer: ";
    cin >> a;

    cout << "Enter second integer: ";
    cin >> b;

    string result = (a >= std::max(a, b)) ? "true" : "false"; 

    cout << result << endl;

    return 0;
}
