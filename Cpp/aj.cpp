#include <iostream>
using namespace std;

class WhichSorpts
{
public:
    int sports;
    void inputSports()
    {
        cout << "Enter Sports Name: ";
        cin >> sports;
    }
};

class Sports
{
public:
    int score;
    void inputScore()
    {
        cout << "Enter Sports Score: ";
        cin >> score;
    }
};

class Academics
{
public:
    int marks;
    void inputMarks()
    {
        cout << "Enter Academic Marks: ";
        cin >> marks;
    }
};

class Student : public Sports, public Academics, public WhichSorpts
{
public:
    void total()
    {
        cout << "Total Score: " << score + marks << endl;
    }
};  

int main()
{
    Student s;
    s.inputSports();
    s.inputScore();
    s.inputMarks();
    s.total();
    return 0;
}