#include <iostream>
using namespace std;

int main() {
    int marks;
    cout << "Enter marks: ";
    cin >> marks;   

    string result = (marks >= 40) ? "Pass" : "Fail";
    cout << "Result: " << result;

    return 0;
}