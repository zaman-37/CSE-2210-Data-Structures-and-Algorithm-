// Class Task - 2:


#include <bits/stdc++.h>
using namespace std;

class bank{
    int acc;
    string name;
    float blnc = 0;

    public: 
    void get () {
        cout << "Enter account number: ";
        cin >> acc ;
        cout << "Enter name: ";
        cin >> name;
        float tem;
        cout << "Enter initial balance: ";
        cin >> tem;
        blnc += tem;
    }

    void disp() {
        cout << endl;
        cout << "name: " << name << endl;
        cout << "Account: " << acc << endl;
        cout << "Balance: " << blnc << endl << endl << endl;
    }

    void deposit () {
        cout << "Enter deposit amount: ";
        float am;
        cin >> am;
        blnc += am;
    }

    void withdraw () {
        cout << "Enter withdraw amount: ";
        float am;
        cin >> am;

        if (blnc >= am) {
            blnc -= am; 
        } else {
            cout << "Balance is not sufficient." << endl; 
        }
    }
};


int main() {
    bank b1;
    b1.get();
    b1.disp();

    b1.deposit();
    b1.disp();

    b1.withdraw();
    b1.disp();

    return 0;
}


/*
Input and Output: 

Enter account number: 2109037
Enter name: kamru
Enter initial balance: 4000

name: kamru
Account: 2109037
Balance: 4000


Enter deposit amount: 100

name: kamru
Account: 2109037
Balance: 4100


Enter withdraw amount: 300

name: kamru
Account: 2109037
Balance: 3800
*/