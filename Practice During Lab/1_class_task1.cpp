                                                // Class Task - 2:

#include <bits/stdc++.h>
using namespace std;

class student{
    string name, study;
    int roll;
    float grd[10];

    public: 
    void get () {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter roll: ";
        cin >> roll;
        cout << "Enter grade of 5 subject: " << endl;
        for (int i=0; i<5; i++) {
            cin >> grd[i];
        }
    }

    void avg () {
        float tol = 0;
        float mx = -10;
        for (int i=0 ; i<5; i++) {
            tol += grd[i];
            mx = max(mx, grd[i]); 
        }
        tol /= 5;
        cout << "Aveeage: " << tol << endl;
        cout << "Max: " << mx << endl;
    }
};


int main() {
    student s1;
    s1.get();
    s1.avg();
    

    return 0;
}