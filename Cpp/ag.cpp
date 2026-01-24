#include<iostream>
using namespace std;

class student {
public:
    int roll = 1;
};

class marks : public student {
public:
    int m1 = 80, m2 = 85;

};
class result : public marks{
public: 
    void display(){
        cout << "Roll Number = " << roll << endl;
        cout << "total marks = " << m1 + m2 << endl;
    }
};

int main (){
    result r;
    r.display();
    return 0;
}