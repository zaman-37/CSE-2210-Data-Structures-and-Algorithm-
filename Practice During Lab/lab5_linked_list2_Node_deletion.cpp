// There are 5 kind of deletetion in linked list. 

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

void delete_first() {
    Node *temp = head->link;
    head = temp;
}

void delete_last() {
    Node *ptr = head;
    Node *prev;
    while (ptr->link != NULL) {
        prev = ptr;
        ptr = ptr->link;
    }
    prev->link = NULL;
    tem = prev;
}

void delete_centre(int srch) {
    Node *ptr = head;
    Node *prev;
    while (ptr->info != srch) {
        prev = ptr;
        ptr = ptr->link;
    }
    prev->link = ptr->link;
}

void delete_before(int srch) {
    Node *ptr = head;
    Node *prev;
    while (ptr->info != srch) {
        prev = ptr;
        ptr = ptr->link;
    }
    delete_centre(prev->info);
}


void delete_after(int srch) {
    Node *ptr = head;
    while (ptr->info != srch) {
        ptr = ptr->link;
    }
    ptr = ptr->link;
    delete_centre(ptr->info);
}

int main() {
    allocate(10);
    allocate(20);
    allocate(30);
    allocate(40);
    allocate(50);
    allocate(60);
    allocate(70);
    allocate(80);
    allocate(90);
    allocate(100);
    allocate(110);
    allocate(120);
    traverse();
    
    cout << endl << "After deleting first Node: ";
    delete_first();
    traverse();

    cout << endl << "After deleting last Node: ";
    delete_last();
    traverse();

    cout << endl << "After deleting a given Node: ";
    delete_centre(60);
    traverse();

    cout << endl << "After deleting previous Node of a given node: ";
    delete_before(50);
    traverse();

    cout << endl << "After deleting next Node of a given node: ";
    delete_after(90);
    traverse();

    return 0;
}