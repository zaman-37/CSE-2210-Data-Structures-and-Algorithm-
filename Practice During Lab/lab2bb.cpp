/// problem 2 solve

#include <bits/stdc++.h>
using namespace std;



int main() {
    cout << "Enter number of word: ";
    int n;
    cin >> n;
    map<string, int> mp;
    for (int i=0; i<n; i++) {
        string tem;
        cin >> tem;
        mp[tem]++;
    }

    cout << "Name: " << "   " << "frequency " << endl;
    for (auto u : mp) {
        cout << u.first << "    " << u.second << endl;
    }
    

    return 0;
}

/*
11
kamru 
hasib
eesa
alex
murphy
kamru
hasib
kamru
supto
raiyan
eesa 

output: 
Name:    frequency
alex        1
eesa        2
hasib       2
kamru       3
murphy      1
raiyan      1
supto       1
*/