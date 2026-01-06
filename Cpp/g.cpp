#include <iostream>
using namespace std;

int main(){
    int a,b,sum,sub,mul,div;

    cout << "Enter first Number: ";
    cin >> a;

    cout << "Enter second numer: ";
    cin >> b;

    sum =a+b;
    sub=a-b;
    mul=a*b;
    div=a/b;

    cout << "Sum = " << sum << endl;
    cout << "Substraction = " << sub << endl;
    cout << "Multiplication = " << mul << endl;
    cout << "Division = " << div << endl;
}