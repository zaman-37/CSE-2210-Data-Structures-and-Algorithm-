#include <bits/stdc++.h>
using namespace std;

class Book{
    public: 
    string title;
    string author;
    string isbn; 
    bool status; 
    void get() {
        cin >> title >> author >> isbn ;
        char ch;
        cin >> ch;
        if (ch == 'Y' || ch == 'y') status = true;
        else status = false;
    }

    void chk_book (Book a[], int n) { 
        string tem; 
        cout << "Enter book name to check: ";
        cin >> tem;
        bool fl = false;
        for (int i=0; i<n; i++) {
            string s = a[i].title;
            if (s == tem) {
                fl = true;
                break;
            }
        }
        if (fl) cout << "The book is available!!!" << endl;
        else cout << "The book is not available!!!" << endl;
    }

    Book get_book (Book a[], int n) {
        cout << "Enter book name to get: ";
        string tem;
        cin >> tem;
        Book ans;
        for (int i=0; i<n; i++) {
            string s = a[i].title;
            if (s == tem) {
                ans = a[i];
                break;
            }
        }
        return ans;
    }

    void disp_all (Book a[], int n) {
        cout << "Total Book: " << n << endl;
        for (int i=0; i<n; i++) {
            cout << a[i].title << endl;
        }
    }

};

int main() {
    cout << "Enter number of Books to store in the Library: ";
    int n;
    cin >> n;
    Book b[n];
    for (int i=0; i<n; i++) {
        Book tem;
        tem.get();
        b[i] = tem;
    }
    cout << endl;

    Book b2;
    b2.chk_book(b, n);
    Book b3 = b2.get_book(b, n);
    cout << b3.title << endl << endl;
    b2.disp_all(b, n);

    return 0;
}
/*
Output Formate:
Enter number of Books to store in the Library: 5
Physics Topon_sir       NCTB            y
Chemistry       Hazari_sir      NCTB            y
Mathematics     Guho_sir        NCTB            y
Biology         Azmol_sir       NCTB            y
English         Murphy  NCTB            y

Enter book name to check: English
The book is available!!!
Enter book name to get: Biology
Biology

Total Book: 5
Physics
Chemistry
Mathematics
Biology
English
*/




// cout << "Enter the title: ";
// cin >> title;
// cout << "Enter autor: ";
// cin >> author;
// cout << "ISBN: ";
// cin >> isbn;
// cout << "Availability (Y/N) or (y/n):";