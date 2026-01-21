#include <iostream>
using namespace std;

int main() {
    int choice;
    double area = 0.0, len, wid, base, height, radius, side;
    float pi = 3.14;
    cout << "Enter shape (1=Rectangle, 2=Square, 3=Triangle, 4=Circle): ";
    cin >> choice;

    switch(choice) {
        case 1:  
            cout << "Enter length and width: ";
            cin >> len >> wid;
            area = len * wid;
            cout << "Rectangle area: " << area << endl;
            break;
        case 2:  
            cout << "Enter side: ";
            cin >> side;
            area = side * side;
            cout << "Square area: " << area << endl;
            break;
        case 3:  
            cout << "Enter base and height: ";
            cin >> base >> height;
            area = 0.5 * base * height;
            cout << "Triangle area: " << area << endl;
            break;
        case 4:  
            cout << "Enter radius: ";
            cin >> radius;
            area = pi * radius * radius;
            cout << "Circle area: " << area << endl;
            break;
        default:
            cout << "Invalid choice, dumbass—1 to 4 only!" << endl;
    }
    return 0;
}
