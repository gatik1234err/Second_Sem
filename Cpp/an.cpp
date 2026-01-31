#include <iostream>
using namespace std;

int main() {
    int arr[2][2];
    int (*p)[2] = arr;
    
    cout << "Enter elements of array:\n";
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            cin >> *(*(p + i) + j);
        }
    }

    cout << *(*(p + 0) + 0) << endl;
    cout << *(*(p + 1) + 1) << endl;
    
    return 0;
}   