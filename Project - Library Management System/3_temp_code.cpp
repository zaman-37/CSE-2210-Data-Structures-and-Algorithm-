#include <bits/stdc++.h>
using namespace std;

class Qn {
public:
    string info;
    Qn* link;
    Qn() : info(""), link(nullptr) {}
};

class Queue {
private:
    Qn* first;
    Qn* rear;

public:
    Queue() : first(nullptr), rear(nullptr) {}

    void enqueue(string s) {
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

    void dequeue() {
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

    bool isEmpty() { return first == nullptr; }

    string front() { return first ? first->info : ""; }

    void traverse() {
        Qn* temp = first;
        while (temp != nullptr) {
            cout << temp->info << " ";
            temp = temp->link;
        }
        cout << endl;
    }

    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
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
    void get_book() {
        cin >> title >> author >> ISBN;
        status = "available";
    }

    void disp() {
        cout << title << "\t" << author << "\t" << ISBN << "\t" << status << endl;
    }

    string get_ISBN() { return ISBN; }
    string get_author() { return author; }
    string get_title() { return title; }
    string get_status() { return status; }

    void set_status(string new_status) { status = new_status; }

    void add_to_reservation(string borrower_name) {
        reservationQueue.enqueue(borrower_name);
    }

    bool has_reservation() {
        return !reservationQueue.isEmpty();
    }

    string get_next_reservation() {
        if (!reservationQueue.isEmpty()) {
            string name = reservationQueue.front();
            reservationQueue.dequeue();
            return name;
        }
        return "";
    }

    void display_reservations() {
        cout << "Reservation Queue for " << title << ": ";
        reservationQueue.traverse();
    }
};

class Stack {
private:
    struct Sn {
        Book info;
        Sn* link;
        Sn() : link(nullptr) {}
    };
    Sn* first;

public:
    Stack() : first(nullptr) {}

    void push(Book s) {
        Sn* ptr = new Sn();
        ptr->info = s;
        ptr->link = first;
        first = ptr;
    }

    void pop() {
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

    Book top() {
        return first->info;
    }

    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }
};

class Library {
private:
    vector<Book> books;
    Stack recentTransactions;

public:
    void store_books();
    void view_books();
    void borrow_book(string ttl, string borrower);
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
    }
}

void Library::view_books() {
    cout << "Title\tAuthor\tISBN\tStatus" << endl;
    for (auto& b : books) {
        b.disp();
    }
}

void Library::borrow_book(string ttl, string borrower) {
    for (auto& b : books) {
        if (b.get_title() == ttl) {
            if (b.get_status() == "available") {
                b.set_status("unavailable");
                recentTransactions.push(b);
                cout << borrower << " has borrowed the book: " << endl;
                b.disp();
                return;
            } else {
                cout << "Book is unavailable. Adding " << borrower << " to the reservation queue." << endl;
                b.add_to_reservation(borrower);
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
                string nextBorrower = b.get_next_reservation();
                if (nextBorrower != "") {
                    cout << "Book is now borrowed by " << nextBorrower << endl;
                } else {
                    b.set_status("available");
                    cout << "Book returned and now available: " << endl;
                    b.disp();
                }
                recentTransactions.push(b);
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

int main() {
    Library lb;
    lb.store_books();
    cout << endl << endl;
    lb.view_books();

    cout << endl << endl;
    lb.borrow_book("1984", "Alice");
    cout << endl << endl;
    lb.borrow_book("1984", "Bob");
    cout << endl << endl;
    lb.return_book("1984");
    cout << endl << endl;
    lb.recent_transaction();


    return 0;
}
