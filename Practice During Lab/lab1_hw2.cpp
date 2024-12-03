#include <bits/stdc++.h>
using namespace std;

class employee {
    public: 
    string name;
    int id;
    string dept;
    double salary;

    void get () {
        cin >> name >> id >> dept >> salary;
    }

    void disp_all (vector<employee> &e) {
        cout << endl;
        string tem;
        cout << "Enter name of department to search: ";
        cin >> tem;
        for (auto u : e) {
            if (u.dept == tem)
                cout << u.name << endl;
        }
    }

    void add (vector<employee> &e) {
        employee tem;
        tem.get();
        e.push_back(tem);
    }

    void srch (vector<employee> &e) {
        int tem;
        cout << "Enter employee id to search: ";
        cin >> tem;
        bool fl = false;
        for (auto u : e) {
            if (u.id == tem) {
                fl = true;
                break;
            }
        }

        if (fl) cout << "Employee found !!!" << endl;
        else cout << "Employee not found !!!" << endl;
    }
};

int main() {
    
    vector<employee> e1;
    int n;
    cout << "Enter number of employee: ";
    cin >> n;
    for (int i=0; i<n; i++) {
        employee tem;
        tem.get();
        e1.push_back(tem);
    }

    employee e2;
    e2.add(e1);
    e2.srch(e1);
    e2.disp_all(e1);
    

    return 0;
}


/*
Output formate: 
Enter number of employee: 5
Kamru           2109037 engineer        1000000
Akib            2109048 engineer        900000
Fahian          2109062 biologist       800000
Charka          2109031 teacher                 700000
Galib           2109069 scientist       50000

sadik 2109047 engineer 300000
Enter employee id to search: 2109037
Employee found !!!

Enter name of department to search:engineer
Kamru
Akib
sadik
*/