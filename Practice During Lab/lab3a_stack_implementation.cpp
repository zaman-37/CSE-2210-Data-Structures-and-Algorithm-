#include <bits/stdc++.h>
using namespace std;

const int MX = 5;

class Stack{
    public: 
    int top;
    int arr[MX];

    Stack() {
        top = -1;
    }

    bool isEmpty () {
        return top == -1;
    }
    bool isFull() {
        return top == MX-1;
    }

    void push(int v) {
        if (isFull()) {
            cout << "Stack overflow" << endl;
        }
        else {
            top ++;
            arr[top] = v;
            cout << "Element is insertd!!" << endl;
        }
    }

    void pop () {
        if (isEmpty()) {
            cout << "Stack underflow"  << endl;
        }
        else {
            int tem = arr[top];
            top--;
            cout << "Element is poped!" << endl;
        }
    }

    int peek (int a) {
        if (isEmpty()) {
            cout << "Stack underflow!! " << endl;
        }
        else {
            return arr[top];
        }
    }

    void traverse() {
        for (int i=0; i<=top; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(5);
    st.push(6);
    
    st.traverse();

    st.pop();
    st.traverse();

    return 0;
}