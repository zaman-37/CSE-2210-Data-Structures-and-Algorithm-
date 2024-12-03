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
    if (head == NULL) {
        head = ptr;
    } else {
        tem->link = ptr;
    }
    tem = ptr;
}

void traverse() {
    Node *ptr = head;
    while (ptr != NULL) {
        cout << ptr->info << " ";
        ptr = ptr->link;
    }
    cout << endl;
}

Node *tail ;
void reverse_list(Node *a) {
    if (a->link == NULL) {
        tail = a;
        return;
    }

    reverse_list(a->link);
    Node *temp = a->link;
    temp->link = a;
    if (a == head) {
        a->link = NULL;
        head = tail;
    }
}

// Hi I am kamruzzaman. 
class Node {
    
};

int main() {
    allocate(10); 
    allocate(20); 
    allocate(30); 
    traverse();

    reverse_list(head);
    traverse();

    return 0;
}