#include <bits/stdc++.h>
using namespace std;

const int MX = 1e5;
const int inf = -2147483647;

class Stack{
    int peak;
    int arr[MX];

    public: 
    Stack() { peak = -1; }
    void push(int a) {
        if (peak <= MX-1) arr[++peak] = a;
        else cout << "Stack overflow!!!" << endl;
    }

    void pop() {
        if (peak == -1) cout << "Stack underflow!!!" << endl;
        else peak--;
    }

    int size() { return peak+1; }
    bool isEmpty() { return peak == -1; }
    int top() { 
        if (peak == -1) return -1;
        return arr[peak];
    } 
};


int n;
void NGE (int arr[], int ans[]) {
    Stack e1;
    for (int i=1; i<=n; i++) {
        if (e1.isEmpty()) e1.push(i);
        else {
            while (arr[i] > e1.top()) {
                int tem = e1.top(); 
                e1.pop();
                ans[tem] = arr[i];
                if (e1.isEmpty()) break;
            }
            e1.push(i);
        }
    }
}

int main() {
    cin >> n;
    Stack e1;
    int arr[n+10];
    int nge[n+10] ;
    for (int i=0; i<n+10; i++) nge[i] = -1;
    for (int i=1; i<=n; i++) {
        cin >> arr[i];
    }

    NGE(arr, nge);
    cout << "Next greater element: ";
    for (int i=1; i<=n; i++) {
        cout << nge[i] << " ";
    }
    cout << endl;

    return 0;
} 

/*
8
8 1 7 2 6 3 5 4
Next greater element: 7 7 6 6 -1 -1 -1 -1 
*/