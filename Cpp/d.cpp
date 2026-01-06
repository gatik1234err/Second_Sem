#include <iostream>
using namespace std;

int main(){
    int a=10, b=20;
    //logical AND (&&) operator
    if (a<15&&b>15){
        cout<<"Both conditions are true"<<endl;
    }
    else{
        cout<<"Both conditions are false"<<endl;
    }

    //logical OR (||) operator
    if (a<15||b<15){
        cout<<"At least one condition is true"<<endl;
    }
    else{
        cout<<"OR conditions are false"<<endl;
    }

    //logical NOT (!) operator
    if (!(a<b)){
        cout<<"Condition is false"<<endl;
    }
    else{
        cout<<"Condition is true"<<endl;
    }

    return 0;
}
