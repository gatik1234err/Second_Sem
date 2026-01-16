#include <iostream> 
using namespace std;

class Rectangle {
private:
    double length;
    double width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}

    double getArea() const {
        return length * width;
    }
};

int main() {
    Rectangle rect(5.0, 3.0);
    cout << "Area: " << rect.getArea() << endl;
    return 0;
}