#include <iostream>
using namespace std;

int main(){
    string s1 = "Hello";
    string s2 = "World";
    string s3;

    s3 = s1 + " " +s2;
    cout << "Concat:" << s3 << endl;

    s1 += s2;
    cout << "Append" << s1 << endl;

    if (s1 == s2) {
        cout << "strings equal" << endl;
    } else {
        cout << "Not Equal" << endl;

    }

    cout << "First char" << s2[0] << endl;

    return 0;

}