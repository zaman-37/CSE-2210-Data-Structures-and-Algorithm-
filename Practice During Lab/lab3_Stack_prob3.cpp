// Evaluate Postfix Expression ... ... ... 

#include <bits/stdc++.h>
using namespace std;

const int MX = 1e5;

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
        if (isEmpty()) cout << "Stack underflow!!!" << endl;
        else peak--;
    }

    bool isEmpty() { return peak == -1; }
    int size() { return peak+1; }
    int top() {
        if (isEmpty()) { return -1; } 
        else return arr[peak];
    } 
};

int main() {
    cout << "Enter the size of the string: ";
    int n;
    cin >> n;
    Stack e1; 
    for (int i=0; i<n; i++) { 
        char a; cin >> a; 
        if (isdigit(a)) {
            int num = a - '0';
            e1.push(num); 
        }
        else {
            int x = e1.top(); e1.pop();
            int y = e1.top(); e1.pop();
            switch (a) {
                case '+': 
                    e1.push(y+x);
                    break;
                case '-':
                    e1.push(y-x);
                    break;
                case '*':
                    e1.push(y*x);
                    break;
                case '/':
                    e1.push(y/x);
                    break;
            }
        }
    }
    cout << e1.top() << endl;

    return 0;
}

/*
Input and output formate:
Enter the size of the string: 7
231*+9-
-4
*/