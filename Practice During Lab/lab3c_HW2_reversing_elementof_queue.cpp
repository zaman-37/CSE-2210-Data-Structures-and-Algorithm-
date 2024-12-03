
#include <bits/stdc++.h>
using namespace std;

class Queue {
    int front, rear;
    int arr[5]; 

public:
    Queue() {
        front = rear = -1; 
    }

    bool isFull() {
        return rear == 4; 
    }

    bool isEmpty() {
        return front == -1; 
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue overflow" << endl;
        } else {
            if (front == -1) front = 0;
            arr[++rear] = value;
            cout << "Enqueued: " << value << endl;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue underflow" << endl;
        } else {
            cout << "Dequeued: " << arr[front++] << endl;
            if (front > rear) front = rear = -1; 
        }
    }

    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        } else {
            return arr[front];
        }
    }

    int size() {
        if (isEmpty()) return 0;
        return rear - front + 1;
    }

    void traverse () {
        for (int i=front; i<=rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void Reverse() {
        int a = front;
        int b = rear;
        while (a<b) {
            swap(arr[a], arr[b]);
            a++;
            b--;
        }
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.traverse();
    
    q.Reverse();
    q.traverse();
    
    return 0;
}