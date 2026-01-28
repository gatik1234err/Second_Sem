#include <iostream>
#include <algorithm>  
using namespace std;

int main() {
    int size;
    cout << "How many numbers? ";
    cin >> size;
    
    int* arr = new int[size];  
    

    for(int i = 0; i < size; i++) {
        cout << "Number " << i+1 << ": ";
        cin >> arr[i];
    }
    

    sort(arr, arr + size);
    

    cout << "Sorted: ";
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    delete[] arr;
    return 0;
}
