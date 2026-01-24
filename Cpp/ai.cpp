#include<iostream>
using namespace std;

class student {  
public:
    int roll;
};

class marks : public student {  
public:
    int m1, m2;
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
    cout << "Enter Roll Number";
    cin >> r.roll;
    cout << "Enter m1 and m2 marks: ";
    cin >> r.m1 >> r.m2;
    r.display();
    return 0;
}
