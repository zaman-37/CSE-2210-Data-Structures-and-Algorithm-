#include <bits/stdc++.h>
using namespace std;

class Node{
    public: 
    int info;
    Node *link;
};

Node *head = NULL, *last;
void allocate (int a) {
    Node *ptr = new Node();
    ptr->info = a;
    ptr->link = NULL;
    if (head == NULL) {
        head = ptr;
    } else {
        last->link = ptr;
    }
    last = ptr;
}

void traverse() {
    Node *ptr = head;
    while (ptr != NULL) {
        cout << ptr->info << " ";
        ptr = ptr->link;
    }
    cout << endl;
}

int main() {
    allocate(1);
    allocate(2);
    allocate(3);
    allocate(4);
    allocate(5);
    allocate(6);
    traverse();
    

    return 0;
}