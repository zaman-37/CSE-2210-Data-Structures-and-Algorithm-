//  problem 3 solve

#include <bits/stdc++.h>
using namespace std;



int main() {
    
    int sz;
    cin >> sz;
    map<int, int> mp;
    for (int i=0; i<sz; i++) {
        int a;
        cin >> a;
        mp[a]++;
    }

    bool fl = false;
    for (auto u: mp) {
        if (u.second > 1) {
            fl = true;
            break;
        }
    }

    if (fl) cout << "Duplicates exist !!!" << endl; 
    else cout << "Duplicates not exist !!!" << endl; 
    

    return 0;
}

/*
8
1 2 3 4 5 6 7 8
output: Duplicates not exist !!!

10
1 1 2 3 4 4 5 6 7 8
output: Duplicates exist !!!
*/
