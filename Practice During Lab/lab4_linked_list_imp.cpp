#include <bits/stdc++.h>
using namespace std;

class Node {
    public: 
    int info;
    Node *link;
};

Node *head = NULL, *tem;

void allocate(int data) {
    Node *ptr = new Node();
    ptr->info = data;
    ptr->link = NULL;

    if (head == NULL) {
        head = ptr;
    } else {
        tem->link = ptr;
    }
    tem = ptr;
}

void traverse() {
    Node *temp = head;

    while(temp != NULL) {
        cout << temp->info << " ";
        temp = temp->link;
    }
    cout << endl;
}

void insert_first(int a) {
    Node *ptr = new Node();
    ptr->info = a;
    ptr->link = head;
    head = ptr;
}

void insert_end(int a) {
    Node *ptr = new Node();
    ptr->info = a;
    ptr->link = NULL;
    Node *temp = head;
    while (temp->link != NULL) {
        temp = temp->link;
    }
    temp->link = ptr;
    tem = ptr;
}

void insert_after(int srch, int a) {
    Node *ptr = new Node();
    ptr->info = a;
    Node *temp = head;
    while (temp->info != srch) {
        temp = temp->link;
    }
    ptr->link = temp->link;
    temp->link = ptr;
}

void insert_before(int srch, int a) {
    Node *ptr = new Node();
    ptr->info = a;
    Node *temp = head, *bef;
    while (temp->info != srch) {
        bef = temp;
        temp = temp->link;
    }
    ptr->link = temp;
    bef->link = ptr;
}


int main() {
    allocate(10);
    allocate(20);
    allocate(30);
    allocate(40);
    allocate(50);
    traverse();
    
    cout << endl << "After inserting 60 at first: ";
    insert_first(60);
    traverse();

    cout << endl << "After inserting 100 at end: ";
    insert_end(100);
    traverse();

    cout << endl << "After inserting 47 after 40: ";
    insert_after(40, 47);
    traverse();

    cout << endl << "After inserting 37 before 40: ";
    insert_before(40, 37);
    traverse();

    return 0;
}