// MIN Stack

#include <bits/stdc++.h>
using namespace std;

const int MX = 1e5;
const int inf = 2147483647;

class Stack {
    int peak;
    int arr[MX];
    int MIN;

    public: 
    Stack() {
        peak = -1;
        MIN = inf;
    }

    void push(int a) {
        if (peak <= MX-1) {
            arr[++peak] = a;
            MIN = min(MIN, a);
        }
        else cout << "Stack overflow!!!" << endl;
    }

    void pop() {
        if (peak == -1) cout << "Stack underflow!!!" << endl;
        else peak--;
    }

    bool isEmpty() {
        return peak == -1;
    }

    int size() {
        return peak+1;
    }

    int top() {
        if (isEmpty()) return -1;
        else return arr[peak];
    }

    int minimum() {
        if (isEmpty()) return -1;
        else return MIN;
    }
};

int main() {
    cout << "Enter the size the Stack: ";
    int n;
    cin >> n;
    Stack e1;
    for (int i=0; i<n; i++) {
        int a; cin >> a;
        e1.push(a);
    }

    cout << "Minimum of Stack: " << e1.minimum() << endl;

    return 0;
}

/*
Input and Output formate:
Enter the size the Stack: 5
1 2 3 4 5
Minimum of Stack: 1
*/