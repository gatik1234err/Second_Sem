#include <iostream>
using namespace std;

class Shape {
public:
    void draw() { cout << "Drawing Shape" << endl; }
    ~Shape() {}
};

class Rectangle : public Shape {
public:
    float length, breadth;
    Rectangle(float l = 0, float b = 0) : length(l), breadth(b) {}
    void draw() { 
        cout << "Drawing Rectangle" << endl;
        cout << "Area of Rectangle = " << length * breadth << endl;
    }
};

class Circle : public Shape {
public:
    float radius;
    Circle(float r = 0) : radius(r) {}
    void draw() { 
        cout << "Area of Circle = " << 3.14 * radius * radius << endl;
    }
};



int main() {
    float l, b, r;
    
    cout << "Enter length of rectangle: ";
    cin >> l;
    cout << "Enter breadth of rectangle: ";
    cin >> b;
    Rectangle* rect = new Rectangle(l, b);
    Shape* shape1 = rect;
    shape1->draw();
    delete rect;  
    
    cout << endl << "Enter radius of circle: ";
    cin >> r;
    Circle* circ = new Circle(r);
    Shape* shape2 = circ;
    shape2->draw();  
    delete circ;
    
    return 0;
}
