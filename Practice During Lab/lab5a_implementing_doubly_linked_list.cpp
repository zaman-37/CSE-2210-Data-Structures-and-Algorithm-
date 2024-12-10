#include <iostream>
using namespace std;

// Node structure for doubly linked list
class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int value) : data(value), prev(nullptr), next(nullptr) {}
};

// Doubly Linked List class
class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    // Constructor
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // Insert at the beginning
    void insertAtBegin(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) { // List is empty
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode; 
        }
    }

    // Insert at the end
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (tail == nullptr) { // List is empty
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void allocate(int value) {
        if (head == nullptr) {
            insertAtBegin(value); // If list is empty, insert at the beginning
        } else {
            insertAtEnd(value); // Otherwise, insert at the end
        }
    }


    // Insert in sorted order
    void insertSorted(int value) {
        Node* newNode = new Node(value);

        // Case 1: List is empty
        if (head == nullptr) {
            head = tail = newNode;
            return;
        }

        // Case 2: Insert at the beginning
        if (value <= head->data) {
            insertAtBegin(value);
            return;
        }

        // Case 3: Insert in the middle or at the end
        Node* current = head;
        while (current->next != nullptr && current->next->data < value) {
            current = current->next;
        }

        // Insert after current
        newNode->next = current->next;
        newNode->prev = current;

        if (current->next != nullptr) {
            current->next->prev = newNode;
        } else {
            tail = newNode; // Update tail if inserted at the end
        }
        current->next = newNode;
    }

    // Traverse forward
    void traverseForward() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Traverse backward
    void traverseBackward() {
        Node* current = tail;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->prev;
        }
        cout << endl;
    }

    // Delete a node by value
    void deleteNode(int value) {
        if (head == nullptr) {
            cout << "List is empty, nothing to delete.\n";
            return;
        }

        // Case 1: Delete head
        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            if (head != nullptr) {
                head->prev = nullptr;
            } else {
                tail = nullptr; // List is now empty
            }
            delete temp;
            return;
        }

        // Case 2: Delete in the middle or end
        Node* current = head;
        while (current != nullptr && current->data != value) {
            current = current->next;
        }

        if (current == nullptr) {
            cout << "Value not found in the list.\n";
            return;
        }

        // Update links
        if (current->next != nullptr) {
            current->next->prev = current->prev;
        } else {
            tail = current->prev; // Update tail if the last node is deleted
        }

        if (current->prev != nullptr) {
            current->prev->next = current->next;
        }

        delete current;
    }

    // Destructor to free memory
    ~DoublyLinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
};

int main() {
    DoublyLinkedList dll;

    // Insert nodes
    dll.insertAtEnd(10);
    dll.insertAtBegin(5);
    dll.insertAtEnd(20);
    dll.insertSorted(15);

    // Traverse forward
    cout << "Forward traversal: ";
    dll.traverseForward();

    // Traverse backward
    cout << "Backward traversal: ";
    dll.traverseBackward();

    // Delete a node
    dll.deleteNode(15);
    cout << "After deleting 15: ";
    dll.traverseForward();

    dll.deleteNode(5);
    cout << "After deleting 5: ";
    dll.traverseForward();

    return 0;
}
