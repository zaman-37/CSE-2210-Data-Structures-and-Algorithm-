// problem 4 solve

#include <bits/stdc++.h>
using namespace std;



int main() {
    
    string s;
    cout << "Enter the string : ";
    cin >> s;

    stack<char> st;
    for (int i=0; i<s.size(); i++ ) {
        if (s[i] == '(' || s[i]=='{' || s[i]=='[') 
            st.push(s[i]); 
        else {
            st.pop();
        }
    }

    if (st.empty()) cout << "valid" << endl;
    else cout << "not valid" << endl;
    

    return 0;
}

/*
1.
Input: 
(){{[]}}(((((((()))))))){{{{{{}}}}}} 
Output: valid

2. 
Input: 
{{{{)()()[])}
Output: not valid
*/ 