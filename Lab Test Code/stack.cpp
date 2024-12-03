#include <bits/stdc++.h>
using namespace std;

const int MX = 1e5;

class Stack{
    int arr[MX];
    int peak;

    public: 
    Stack(){
        peak = -1;
    }

    void push(int a) {
        if (peak >= MX) {
            cout << "Stack overflow" << endl;
            return;
        }

        arr[++peak] = a;
    }

    void pop() {
        if (peak == -1) {
            cout << "Stack underflow" << endl;
            return ;
        }

        peak--;
    }

    int top() {
        return arr[peak];
    }
    int size() {
        return peak+1;
    }

    bool isEmpty() {
        return peak == -1;
    }
};

int main() {
    
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    while (!s.isEmpty() ) {
        cout << s.top() << endl;
        s.pop();
    }
    

    return 0;
}