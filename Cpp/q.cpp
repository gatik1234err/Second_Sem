#include <iostream>
using namespace std;

int main() {
    int n, t1 = 0, t2 = 1, next;
    cout << "Enter limit: ";
    cin >> n;
    cout << "Fibonacci: " << t1 << " " << t2 << " ";
    next = t1 + t2;
    while (next <= n) {
        cout << next << " ";
        t1 = t2;
        t2 = next;
        next = t1 + t2;
    }
    cout << endl;
    return 0;
}