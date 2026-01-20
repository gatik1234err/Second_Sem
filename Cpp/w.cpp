#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
int add (int a, int b){
        return a + b;
}

void greet(){
    cout << "Welcome to cpp Functions\n";
}

bool isEven(int n){
    return(n%2 == 0);
}

void callByValue(int x) {
    x = 100;
    cout << "Inside pf call by Value" << x << endl; 
}

void callByReference(int &x) {
    x = 200;
}

void callByPointer(int *x){
    *x = 300;
    cout << "Call by Pointer" << *x << endl;

}

int main(){

    cout << "\n Call By Value\n";
    int a = 10;
    callByValue(a);
    cout << "After call by Value" << a << endl;

    cout << "\n Call By Reference\n";
    int b = 20;
    callByReference(b);
    cout << "After call by Reference" << b << endl;

    cout << "\n Call By Pointer\n";
    int c = 30;
    callByPointer(&c);
    cout << "After call by Pointer" << c << endl;
}