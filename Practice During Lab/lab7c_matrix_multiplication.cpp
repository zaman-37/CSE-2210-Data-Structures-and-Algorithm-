#include <bits/stdc++.h>
using namespace std;



int main() {
    int n1, m1;
    cin >> n1 >> m1;
    vector<vector<int>> mat1(n1+1, vector<int>(m1+1, 0));
    for (int i=1; i<=n1; i++) {
        for (int j=1; j<=m1; j++) {
            cin >> mat1[i][j]; 
        }
    }

    int n2, m2;
    cin >> n2 >> m2;
    vector<vector<int>> mat2(n2+1, vector<int>(m2+1, 0));
    for (int i=1; i<=n2; i++) {
        for (int j=1; j<=m2; j++) {
            cin >> mat2[i][j]; 
        }
    }

    if (m1 != n2) { 
        cout << "Enter valid row and column" << endl; 
        return 0; 
    } 


    vector<vector<int>> ans(n1+1, vector<int>(m2+1, 0)); 
    for (int i=1; i<=n1; i++) {
        for (int j=1; j<=m2; j++) {
            for (int k=1; k<=m1; k++) {
                ans[i][j] += (mat1[i][k] * mat2[k][j]);
            }
        }
    }


    for (int i=1; i<=n1; i++) {
        for (int j=1; j<=m2; j++) { 
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }


    return 0;
}