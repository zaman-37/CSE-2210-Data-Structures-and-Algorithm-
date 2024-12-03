#include <bits/stdc++.h>
using namespace std;

const int MX = 1e5;

class Queue{
    int arr[MX];
    int frnt, bck;

    public: 
    Queue() {
        frnt = bck = -1;
    }
    void push(int a) {
        if (bck >= MX) {
            cout << "Queue overflow" << endl;
            return;
        }

        arr[++bck] = a;
        if (frnt == -1) frnt ++;
    }

    void pop() {
        if (frnt > bck) {
            cout << "Queue underflow" << endl;
            frnt = bck = -1;
            return;
        }

        frnt ++;
    }

    int front() {
        return arr[frnt];
    }
    int back() {
        return arr[bck];
    }
    bool isEmpty() {
        return (frnt == -1 && bck == -1);
    }
    int size() {
        return (bck-frnt+1);
    }
    void traverse() {
        for (int i=frnt; i<=bck; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void reverse() {
        int l = frnt;
        int m = bck;
        while (l<m) {
            swap(arr[l], arr[m]);
            l++;
            m--;
        }
    }
};


int main() {
    
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.traverse();

    cout << q.front() << endl;
    cout << q.back() << endl;

    // q.pop();
    // cout << q.front() << endl;
    // cout << q.isEmpty() << endl;

    cout << "size: " << q.size() << endl;

    q.reverse();
    q.traverse();


    return 0;
}

