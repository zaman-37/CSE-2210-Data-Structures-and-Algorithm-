#include <bits/stdc++.h>
using namespace std;

struct person {
    int roll;
    string name;

};

class parent{
    string nm;
    int idl;
};

int main() {
    struct person pi;
    pi.roll = 37;
    pi.name = "Kamruzzaman";
    cout << pi.roll <<  " " << pi.name << endl; 

    return 0;
}