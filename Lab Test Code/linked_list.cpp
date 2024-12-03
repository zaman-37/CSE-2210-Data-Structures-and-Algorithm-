#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int info;
    Node *link;
};

Node *head = NULL, *tem;

void allocate(int a) {
    Node *ptr = new Node();
    ptr->info = a;
    ptr->link = NULL;
    if (head == NULL) {
        head = ptr;
    } 
    else {
        tem->link = ptr;
    }
    tem = ptr;
}

void traverse() {
    Node *temp = head;
    while (temp != NULL) {
        cout << temp->info << " ";
        temp = temp->link;
    }
    cout << endl;
}

void insert_first (int a) {
    Node *ptr = new Node();
    ptr->info = a;
    ptr->link = head;
    head = ptr;
}

void insert_end (int a) {
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

void insert_after(int a, int src) {
    Node *ptr = new Node ();
    ptr->info = a;
    ptr->link = NULL;
    Node *temp = head;
    while (temp->info != src) {
        temp = temp->link;
    }
    ptr->link = temp->link;
    temp->link = ptr;
}

void insert_before (int a, int src) {
    Node *ptr = new Node ();
    ptr->info = a;
    ptr->link = NULL;
    Node *temp = head, *bef;
    
    while (temp->info != src) {
        bef = temp;
        temp = temp->link;
    }
    bef->link = ptr;
    ptr->link = temp;
}

void delete_first() {
    head = head->link;
}

void delete_middle (int a) {
    Node *ptr = head;
    
}


int main() {

    allocate(1);
    allocate(2);
    allocate(3);
    allocate(4);
    allocate(5);
    allocate(6);
    allocate(7);
    traverse();

    insert_first(10);
    insert_end(60);
    insert_before(12, 4);
    insert_after(14, 4);

    traverse();
    

    return 0;
}