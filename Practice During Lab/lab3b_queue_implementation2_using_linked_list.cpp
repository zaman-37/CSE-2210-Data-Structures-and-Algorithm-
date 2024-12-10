#include <bits/stdc++.h>
using namespace std;

class node {
public:
    int info;
    node *link;
    node(int a) : info(a), link(nullptr){}
};

class Queue{
private:
    node *first;
    node *last;
public:
    Queue() : first(nullptr), last(nullptr){}
    void enqueue(int a) {
        node *ptr = new node(a);
        if (last == nullptr ) {
            first = last = ptr;
        }
        else {
            last->link = ptr;
            last = ptr;
        }
    }

    bool isEmpty() {
        return (last == nullptr);
    }

    void dequeue() {
        if (!isEmpty()) {
            first = first->link;
        }
        else {
            cout << "Queue overflow!!!" << endl;
        }
    }

    int front(){
        return (first->info);
    }
    int back(){
        return (last->info);
    }
    void traverse() {
        node *ptr = first;
        while (ptr != nullptr) {
            cout << ptr->info << " ";
            ptr = ptr->link;
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(7);

    q.traverse();
    

    return 0;
}