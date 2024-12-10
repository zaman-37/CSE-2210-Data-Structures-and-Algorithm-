#include <bits/stdc++.h>
using namespace std;

class node {
    public: 
    int info;
    node *link;
    node (int a) : info(a), link(nullptr){}
};

class sorted_linked_list{
private: 
    node *head;
    node *rear;
public:
    sorted_linked_list() : head(nullptr), rear(nullptr){}
    // void allocate(int a) { // This allocate() function is for normal linked list
    //     node *ptr = new node(a);
    //     if (rear == nullptr) {
    //         head = rear = ptr;
    //     }
    //     else {
    //         rear->link = ptr;
    //         rear = ptr;
    //     }
    // }
    void allocate(int a) {
        node *ptr = new node(a);

        // Case 1: List is empty
        if (head == nullptr) {
            head = rear = ptr; // New node is both head and rear 
            return;
        }

        // Case 2: Insert at the beginning (new head)
        if (a < head->info) {
            ptr->link = head; // New node points to current head
            head = ptr;       // Update head to new node
            return;
        }

        // Case 3: Insert in the middle or at the end
        node *current = head;
        while (current->link != nullptr && current->link->info < a) {
            current = current->link; // Move to the next node
        }

        // Insert the new node after `current`
        ptr->link = current->link;
        current->link = ptr;

        // Update rear if the node was added at the end
        if (current == rear) {
            rear = ptr;
        }
    }

    void traverse() {
        node *ptr = head;
        while (ptr != nullptr) {
            cout << ptr->info << " ";
            ptr = ptr->link;
        }
        cout << endl;
    }

};

int main() {
    sorted_linked_list a;
    a.allocate(3);
    a.allocate(1);
    a.allocate(2);
    a.allocate(5);
    a.allocate(4);

    a.traverse();

    return 0;
}