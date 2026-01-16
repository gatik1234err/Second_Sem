#include <iostream>
using namespace std;

class student
{
public:
    int rollNo;
    string name;

    void display()
    {
        cout<<"Roll No: "<<rollNo<<endl;
        cout<<"Enter the name: "<<name<<endl;
    }
};

int main()
{

    student s1;
    s1.rollNo = 101;
    s1.name = "Gb";
    s1.display();
    
    return 0;


}