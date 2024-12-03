#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int info ;
    Node *link;
};

Node * head = NULL, *tem;

void allocate(int a) {
    Node *ptr = new Node();
    ptr->info = a;
    ptr->link = NULL;
    Node *bef, *temp = head;
    if (head == NULL) 
        head = ptr;
    else {
        while (temp->info < a) {
            bef = temp;
            temp = temp->link;
        }


        bef->link = ptr;
        ptr->link = temp;
    }
}

void traverse() {
    Node *temp = head;
    while (temp != NULL) {
        cout << temp->info <<  " ";
        temp = temp->link;
    }
    cout << endl;
}





int main() {
    
    allocate(5);
    allocate(2);
    allocate(3);
    allocate(4);
    allocate(10);
    allocate(6);
    allocate(7);
    traverse();

    return 0;
}