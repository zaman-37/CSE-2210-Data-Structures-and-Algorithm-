#include <bits/stdc++.h>
using namespace std;

const int MX = 1e5;

class Stack {
    int peak;
    int arr[MX];

    public: 
    Stack() {
        peak = -1;
    }
    void push(int a) {
        if (peak > MX-1) {
            cout << "Stack overflow!!!" << endl;
        }
        else {
            arr[++peak] = a; 
        }
    }
    void pop() {
        if (peak == -1) cout << "Stack underflwo!!!" << endl;
        else peak--;
    }

    bool isEmpty() {
        return peak==-1;
    }
    int top() {
        return arr[peak];
    }
    int size() {
        return peak+1;
    }
};

void insert(Stack &a, int el) {
    if (a.isEmpty()) a.push(el);
    else if (a.top() <= el) a.push(el);
    else {
        int tem = a.top();
        a.pop();
        insert(a, el);
        a.push(tem);
    }
}

void sort(Stack &a) {
    if (a.isEmpty()) return;
    int tem = a.top();
    a.pop();

    sort(a);
    insert(a, tem);
}

int main() {
    cout << "Enter Stack size: " ;
    int n;
    cin >> n;
    Stack e1;
    for (int i=0; i<n; i++) {
        int c;
        cin >> c;
        e1.push(c);
    }

    sort(e1); // sorting the stack 

    deque<int> v;
    while (!e1.isEmpty()) {
        int ch = e1.top();
        e1.pop();
        v.push_front(ch);
    }

    for (auto u: v) cout << u << " ";
    cout << endl;

    return 0;
}


/*

Input and output formate: 
Enter Stack size: 6
33 99 12 23 100 2
2 12 23 33 99 100

*/ 