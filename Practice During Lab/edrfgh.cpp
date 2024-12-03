#include <bits/stdc++.h>
using namespace std;

class node {
public:
    int info;         // Data part
    node* link;       // Pointer to the next node
};

node *head = NULL, *temp;  // Global pointers to manage the list

void allocation(int item) {
    node *ptr = new node();  // Allocate a new node
    ptr->info = item;        // Set the data
    ptr->link = NULL;        // Set the link to null

    if (head == NULL) {
        head = ptr;          // If list is empty, the new node becomes head
        temp = ptr;
    } else {
        temp->link = ptr;    // Otherwise, link the last node to the new node
        temp = ptr;
    }
}

void traverse() {
    node *srt = head;        // Start from the head
    while (srt != NULL) {
        cout << srt->info << " ";  // Print data
        srt = srt->link;           // Move to the next node
    }
    cout << endl;
}

void insert_node_before_item(int search, int data){
    node *ptr=new node();
    ptr->info=data;
    node *srt=head,*prev;
    
    while(srt->info!=search){
        prev=srt;
        srt=srt->link;
    }
    prev->link=ptr;
    ptr->link=srt;
}


int main() {
    allocation(10);
	allocation(20);
	allocation(30);
	traverse(); //10 20 30 
	
    insert_node_before_item(20, 15);
    traverse();

    return 0;
}