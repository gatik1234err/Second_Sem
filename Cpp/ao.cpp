#include <iostream>
using namespace std;
class Base {
public:
  virtual void display() { cout << "This is Base class display" << endl; }
};

class Derived : public Base {
public:
  void display() { cout << "This is Derived class display" << endl; }
};
int main() {
  Base *b;
  Derived d;
  b = &d;
  b->display();

  return 0;
}