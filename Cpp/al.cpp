#include <iostream>
using namespace std;


class Account {
protected:
    string name;
    int accNo;
    float balance;

public:
    void inputAccount() {
        cout << "Enter account holder name: ";
        cin >> name;

        cout << "Enter account number: ";
        cin >> accNo;

        cout << "Enter balance: ";
        cin >> balance;
    }
};


class SavingsAccount : public Account {
public:
    float interestRate;

    void inputSavings() {
        cout << "Enter interest rate (%): ";
        cin >> interestRate;
    }

    void show() {
        cout << "Name: " << name << endl;
        cout << "Account No: " << accNo << endl;
        cout << "Balance: " << balance << endl;
        cout << "Interest: " << (balance * interestRate / 100) << endl;
    }
};


class CurrentAccount : public Account {
public:
    float overdraftLimit;

    void inputCurrent() {
        cout << "Enter overdraft limit: ";
        cin >> overdraftLimit;
    }

    void show() {
        cout << "Name: " << name << endl;
        cout << "Account No: " << accNo << endl;
        cout << "Balance: " << balance << endl;
        cout << "Overdraft Limit: " << overdraftLimit << endl;
    }
};

int main() {
    SavingsAccount sa;
    CurrentAccount ca;

    cout << "Enter Savings Account Details\n";
    sa.inputAccount();
    sa.inputSavings();
    sa.show();

    cout << "\nEnter Current Account Details\n";
    ca.inputAccount();
    ca.inputCurrent();
    ca.show();

    return 0;
}