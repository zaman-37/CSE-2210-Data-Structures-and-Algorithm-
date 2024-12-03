// solve of problem 1
#include <bits/stdc++.h>
using namespace std;



int main() {
    int n;
    cin >> n;
    set<int> st;
    map<int, int> mp;

    for (int i=1; i<=n; i++) {
        int a;
        cin >> a;
        if (st.count(a) == 0) {
            st.insert(a);
            mp[i] = a;
        }    
    }

    for (auto u: mp) cout << u.second << " ";
    cout << endl;
    

    return 0;
}

/*
12
3 3 3 3 1 1 5 5 8 8 3 3
output: 3 1 5 8


10
2 3 4 4 5 6 7 8 1 1 
output: 2 3 4 5 6 7 8 1
*/ 