#include <bits/stdc++.h>
using namespace std;

class node{
    public: 
    int info;
    node *link;
    node (int a) : info(a), link(nullptr){}
};

class Stack{
    node *head;
    public:
    Stack() : head(nullptr){}
    void push(int a) {
        node *ptr = new node(a);
        if (head == nullptr) {
            head = ptr;
        }
        else {
            ptr->link = head;
            head = ptr;
        }
    }

    void pop() {
        if (head == nullptr) {
            cout << "Stack overflow!!!" << endl;
            return;
        }
        head = head->link;
    }
    bool isEmpty() {
        return (head == nullptr);
    }
    int top() {
        return head->info; 
    }
};

int main() {
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);

    while (!s.isEmpty()) {
        cout << s.top() << " ";
        s.pop();
    }
    

    return 0;
}