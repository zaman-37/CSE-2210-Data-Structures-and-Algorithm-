#include <bits/stdc++.h>
using namespace std;

class Book{
    private: 
    string title;
    string author;
    string ISBN;
    string status;

    public: 
    void get_book() {
        cin >> title >> author >> ISBN ;
        status = "available";
    }
    void disp() {
        cout << title << "\t" << author << "\t" << ISBN << "\t" << status << endl;
    }
    string get_ISBN() {return ISBN;} 
    string get_author() {return author;} 
    string get_title() {return title;}
};

class node{
    public:
    string nm;
    node *link;
};


class Qn{
    public: 
    string info;
    Qn *link;
    Qn() : info(""), link(nullptr){}
};
class Sn{
    public:
    Book info;
    Sn * link;
    Sn(): link(nullptr){}
};

class Queue{ 
    private: 
    Qn *first;
    Qn *rear;
    public: 
    Queue(): first(nullptr), rear(nullptr){} 
    void enqueue(string s) {
        Qn *ptr = new Qn();
        ptr->info = s;
        ptr->link = nullptr;
        if (rear == nullptr) {
            first = rear = ptr;
        } 
        else {
            rear->link = ptr;
            rear = ptr;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            return;
        }
        Qn *ptr = first;
        first = first->link;
        delete ptr;
    }
    bool isEmpty() {
        return (rear == nullptr && first == nullptr);
    }
    string front() {
        return (first->info);
    }
    string back(){
        return (rear->info);
    }

    void traverse() {
        Qn *temp = first;
        while (temp != nullptr) {
            cout << temp->info << " ";
            temp = temp->link;
        }
        cout << endl;
    }

    ~Queue(){
        while (!isEmpty()) {
            dequeue();
        }
    } 
};


class Stack{
    private: 
    Sn *first;
    int sz;

    public: 
    Stack(): first(nullptr), sz(0){} 
    void push(Book s) {
        Sn * ptr = new Sn(); 
        ptr->info = s;
        ptr->link = nullptr;

        if (first == nullptr){
            first = ptr;
        }
        else {
            ptr->link = first;
            first = ptr;
        }
    }
    void pop(){ 
        if (first == nullptr) { 
            return;
        }
        Sn *ptr = first;
        first = first->link;
        delete ptr;
    }
    bool isEmpty() {
        return first == nullptr;
    }
    Book top(){
        return first->info;
    }
    int size(){
        return sz;
    }
    ~Stack () {
        while (!isEmpty()) {
            pop();
        }
    }
};



int main() {

    int n = 5;
    Stack st;
    for (int i=0; i<n; i++) {
        Book b;
        b.get_book();
        st.push(b);
    }

    cout <<  endl << endl;
    while (!st.isEmpty()) {
        Book b = st.top();
        b.disp();
        st.pop();
    }

    return 0;
}