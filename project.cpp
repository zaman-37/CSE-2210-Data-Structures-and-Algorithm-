#include <bits/stdc++.h>
using namespace std;

class Qn {
public:
    string info, name;
    Qn* link;
    Qn() : info(""), link(nullptr) {}
};

class Queue {
private:
    Qn* first;
    Qn* rear;

public:
    Queue() : first(nullptr), rear(nullptr) {}

    void enqueue(string s) { // adding element to reservation queue
        Qn* ptr = new Qn();
        ptr->info = s;
        ptr->link = nullptr;
        if (rear == nullptr) {
            first = rear = ptr;
        } else {
            rear->link = ptr;
            rear = ptr;
        }
    }

    void dequeue() { // deleting element from reservation queue
        if (isEmpty()) {
            return;
        }
        Qn* ptr = first;
        first = first->link; 
        delete ptr; 
        if (first == nullptr) {
            rear = nullptr;
        }
    }

    bool isEmpty() { return first == nullptr && rear == nullptr; }

    string front() { return (first != nullptr) ? first->info : ""; } 

    void traverse() {
        Qn* temp = first;
        while (temp != nullptr) {
            cout << temp->info << endl;
            temp = temp->link;
        }
        cout << endl;
    }
};

class Book {
private:
    string title;
    string author;
    string ISBN;
    string status;
    Queue reservationQueue;

public:
    void get_book() { // get book information from user
        cin >> title >> author >> ISBN;
        status = "available";
    }

    void disp() {
        cout << title << "\t" << author << "\t" << ISBN << "\t" << status << endl; // display book details
    }

    string get_ISBN() { return ISBN; }
    string get_author() { return author; }
    string get_title() { return title; }
    string get_status() { return status; }

    void set_status(string new_status) { status = new_status; } // change book's status

    void add_to_reservation(string borrower_name) {
        reservationQueue.enqueue(borrower_name);
    }

    bool has_reservation() {
        return !reservationQueue.isEmpty();
    }

    string get_next_reservation() { // get next user name
        if (!reservationQueue.isEmpty()) {
            string name = reservationQueue.front();
            reservationQueue.dequeue();
            return name;
        }
        return "";
    }

    void display_reservations() { // display all user in reservation queue
        cout << "Reservation Queue for " << title << ": " << endl;
        reservationQueue.traverse();
    }
};

class Sn {
public:
    Book info;
    Sn* link;
    Sn() : link(nullptr) {}
};

class Stack {
private:
    
    Sn* first;

public:
    Stack() : first(nullptr) {}

    void push(Book s) { // insert element to top of the stack
        Sn* ptr = new Sn();
        ptr->info = s;
        ptr->link = first;
        first = ptr;
    }

    void pop() { // delete element from top of the stack
        if (first == nullptr) {
            return;
        }
        Sn* ptr = first;
        first = first->link;
        delete ptr;
    }

    bool isEmpty() {
        return first == nullptr;
    }

    Book top() { // return top of the stack
        return first->info;
    }

    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }
};

class BST_node {
public:
    Book data;
    BST_node* left;
    BST_node* right;
    BST_node(Book a) : data(a), left(nullptr), right(nullptr) {}
};

class BST {
private:
    BST_node* root;

    BST_node* insert(BST_node* rt, Book d) { // insert element to binary search tree
        if (rt == nullptr) {
            return new BST_node(d);
        }
        if (d.get_title() <= rt->data.get_title()) {
            rt->left = insert(rt->left, d);
        } else {
            rt->right = insert(rt->right, d);
        }
        return rt;
    }

    void inOrder(BST_node* rt) { // to return all the element in sorted order
        if (rt != nullptr) {
            inOrder(rt->left);
            rt->data.disp();
            inOrder(rt->right);
        }
    }

    BST_node* search(BST_node* rt, const string& title) const { // search element in BST
        if (rt == nullptr || rt->data.get_title() == title) {
            return rt;
        }
        if (title < rt->data.get_title()) {
            return search(rt->left, title);
        } else {
            return search(rt->right, title);
        }
    }

public:
    BST() : root(nullptr) {}

    BST_node* get_root() { return root; }

    void insert(Book d) {
        root = insert(root, d);
    }

    void printInOrder() {
        inOrder(root);
    }

    void search(const string& title) const {
        BST_node* result = search(root, title);
        if (result) {
            cout << "Book found:" << endl;
            result->data.disp();
        } else {
            cout << "Book not found." << endl;
        }
    }
};

class Quick_sort{
    public: 
    void sort(vector<Book> &b, int low, int high) {  // recursively call the sort function to sort
        if (low > high) {
            return;
        }
        int p = partition(b, low, high);
        sort(b, low, p-1);
        sort(b, p+1, high);
    }
    int partition(vector<Book> &bk, int low, int high) { // partitioning of array
        Book pivot = bk[high];
        int i = low;
        for (int j=low; j<=high-1; j++) {
            if (bk[j].get_title() <= pivot.get_title()) {
                swap(bk[i], bk[j]);
                i++;
            }
        }
        swap(bk[i], bk[high]);
        return i;
    }
};


class Library { // main library system
private:
    vector<Book> books;
    BST bst;
    Stack recentTransactions; 

public:
    void store_books(); 
    void view_books(); 
    void sort_by_ISBN();
    void sort_by_title();
    void search_book(string ttl);
    void borrow_book(string ttl, string borrower);
    void view_reservation_queue(); 
    void return_book(string ttl);
    void recent_transaction();
};

void Library::store_books() {
    cout << "Enter the number of books to store: ";
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        Book b;
        b.get_book();
        books.push_back(b);
        bst.insert(b);
    }
}

void Library::view_books() {
    for (auto& b : books) {
        b.disp();
    }
}

void Library::sort_by_ISBN() {
    // Bubble Sort based on ISBN
    for (int i = 0; i < books.size(); i++) {
        for (int j = 1; j < books.size() - i; j++) {
            if (books[j - 1].get_ISBN() > books[j].get_ISBN()) {
                swap(books[j - 1], books[j]);
            }
        }
    }
    cout << "Books sorted by ISBN:" << endl;
    view_books();
}

void Library::sort_by_title() {
    // Quick Sort based on Title
    Quick_sort qs;
    qs.sort(books, 0, books.size() - 1);
    cout << "Books sorted by Title:" << endl;
    view_books();
}

void Library::search_book(string ttl) {
    bst.search(ttl);
}

void Library::borrow_book(string ttl, string borrower) {
    for (auto& b : books) {
        if (b.get_title() == ttl) {
            if (b.get_status() == "available") {
                b.set_status("unavailable"); // update book status
                recentTransactions.push(b); // update recent transaction stack
                cout << borrower << " has borrowed the book: " << endl;
                b.disp();
                return;
            } else {
                cout << "Book is unavailable. Adding " << borrower << " to the reservation queue." << endl;
                b.add_to_reservation(borrower); // if book is not available then, store the user name to reservation queue.
                return;
            }
        }
    }
    cout << "Book not found in the library." << endl;
}

void Library::return_book(string ttl) {
    for (auto& b : books) {
        if (b.get_title() == ttl) {
            if (b.get_status() == "unavailable") {
                // Store next user in the reservation queue
                string nextBorrower = b.get_next_reservation();
                if (!nextBorrower.empty()) {
                    cout << "Book is now borrowed by " << nextBorrower << endl;
                } else {
                    // No reservations left, mark the book as available
                    b.set_status("available");
                    cout << "Book returned and is now available: " << endl;
                    b.disp();
                }
                // Push the book transaction to the stack
                recentTransactions.push(b);
                return;
            } else {
                cout << "Book is not marked as unavailable, nothing to return." << endl;
                return;
            }
        }
    }
    cout << "Book not found in the library." << endl;
}

void Library::recent_transaction() {
    if (recentTransactions.isEmpty()) {
        cout << "No recent transactions available." << endl;
    } else {
        cout << "Most recent transaction: " << endl;
        recentTransactions.top().disp();
    }
}

void Library :: view_reservation_queue() {
    cout << "Enter book title to see reservation: ";
    string s;
    cin >> s;
    for (int i=0; i<books.size(); i++) {
        if (books[i].get_title() == s) {
            books[i].display_reservations();
            break;
        }
    }
}

void my_library() {
    
    cout << "...........................Welcome to Library......................" << endl;
    cout << "..................................................................." << endl;
    cout << "Manue: " << endl;
    cout << "1. Store Books" << endl;
    cout << "2. View Books" << endl;
    cout << "3. Sort Books by ISBN" << endl;
    cout << "4. Sort books by Title" << endl;
    cout << "5. Search Books" << endl;
    cout << "6. Borrow Books" << endl;
    cout << "7. Display Reservation" << endl;
    cout << "8. Return Books" << endl;
    cout << "9. Show Recent Transaction" << endl;
}

int main() {
    Library lb;
    while(1) {
        my_library();
        int n;
        cout << "Enter your choice: " << endl;
        cin >> n;

        if (n == 1) {
            lb.store_books();
        }
        else if (n == 2) {
            lb.view_books();
        }
        else if (n == 3) {
            lb.sort_by_ISBN();
        }
        else if (n == 4) {
            lb.sort_by_title();
        }
        else if (n == 5) {
            string s;
            cout << "Enter Book Title: ";
            cin >> s;
            lb.search_book(s);
        }
        else if (n == 6) {
            string s1, s2;
            cout << "Enter borrower name: ";
            cin >> s1;
            cout << "Enter book title: ";
            cin >> s2;
            lb.borrow_book(s2, s1);
        }
        else if (n == 7) {
            lb.view_reservation_queue();
        }
        else if (n == 8) {
            cout << "Enter book title: ";
            string str;
            cin >> str;
            lb.return_book(str);
        }
        else if (n == 9) {
            lb.recent_transaction();
        }
        else {
            cout << "Enter valid manue!!!" << endl;
        }

        int opt;
        cout << endl;
        cout << "Option:" << endl;
        cout << "1. Go to main manue " << endl;
        cout << "2. Exit" << endl;
        cout << "Ente you choice: ";
        cin >> opt;
        if (opt == 1) {
            system("cls");
        } 
        else {
            break;
        }
    }

    return 0;
}















/*
9
To-Kill-a-Mockingbird       Harper-Lee              978-0-06-112008-4
James-and-the-Giant-Peach   Roald-Dahl              978-0-14-241823-9
The-Great-Gatsby            F-Scott-Fitzgerald      978-0-74-327356-5
Pride-and-Prejudice         Jane-Austen             978-0-19-953556-9
The-Catcher-in-the-Rye      J.D.Salinger            978-0-31-676948-0
Lord-of-the-Flies           William-Golding         978-0-39-950148-7
Charlotte's-Web             E.B.-White              978-0-06-112495-2
1984                        George-Orwell           978-0-45-228423-4
Aesop's-Fables              Aesop                   978-0-48-628020-2

*/

