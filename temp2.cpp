#include <bits/stdc++.h>
using namespace std;
class Book {
public:
    string title;
    string author;
    string ISBN;
    string status; // "available" or "borrowed"
    list<string> borrowHistory;

    Book(string t, string a, string i, string s = "available")
        : title(t), author(a), ISBN(i), status(s) {}
};


class Library {
private:
    vector<Book> books; // Array of books
    map<string, queue<string>> reservations; // Book ISBN -> Queue of borrowers
    stack<string> recentTransactions; // Stack for recent transactions

public:
    void addBook();
    void removeBook(string ISBN);
    void borrowBook(string ISBN, string borrower);
    void returnBook(string ISBN);
    void viewBooks();
    void searchBook(string ISBN);
    void sortBooks(int criteria); // 1: Title, 2: Author, 3: ISBN
};
void Library::addBook() {
    cout << "Enter number of books to add: " << endl;
    int n;
    cin >> n;
    string ttl, auth, isbn;
    cin >> ttl >> auth >> isbn;
    books.push_back(Book(ttl, auth, isbn));
}

void Library::removeBook(string ISBN) {
    for (auto it = books.begin(); it != books.end(); ++it) {
        if (it->ISBN == ISBN) {
            books.erase(it);
            cout << "Book removed successfully: " << ISBN << endl;
            return;
        }
    }
    cout << "Book not found: " << ISBN << endl;
}
void Library::borrowBook(string ISBN, string borrower) {
    for (auto &book : books) {
        if (book.ISBN == ISBN) {
            if (book.status == "available") {
                book.status = "borrowed";
                book.borrowHistory.push_back(borrower);
                recentTransactions.push("Borrowed: " + book.title);
                cout << "Book borrowed successfully by " << borrower << endl;
            } else {
                cout << "Book is currently unavailable. Added to reservations queue." << endl;
                reservations[ISBN].push(borrower);
            }
            return;
        }
    }
    cout << "Book not found: " << ISBN << endl;
}

void Library::returnBook(string ISBN) {
    for (auto &book : books) {
        if (book.ISBN == ISBN) {
            book.status = "available";
            if (!reservations[ISBN].empty()) {
                string nextBorrower = reservations[ISBN].front();
                reservations[ISBN].pop();
                borrowBook(ISBN, nextBorrower);
            }
            recentTransactions.push("Returned: " + book.title);
            cout << "Book returned successfully." << endl;
            return;
        }
    }
    cout << "Book not found: " << ISBN << endl;
}
void Library::viewBooks() {
    cout << "Library Books:\n";
    for (const auto &book : books) {
        cout << "Title: " << book.title << ", Author: " << book.author
             << ", ISBN: " << book.ISBN << ", Status: " << book.status << endl;
    }
}

void Library::searchBook(string ISBN) {
    for (const auto &book : books) {
        if (book.ISBN == ISBN) {
            cout << "Book found: Title: " << book.title << ", Author: " << book.author
                 << ", Status: " << book.status << endl;
            return;
        }
    }
    cout << "Book not found: " << ISBN << endl;
}
void Library::sortBooks(int criteria) {
    switch (criteria) {
    case 1: // Sort by title
        sort(books.begin(), books.end(), [](Book a, Book b) { return a.title < b.title; });
        cout << "Books sorted by title.\n";
        break;
    case 2: // Sort by author
        sort(books.begin(), books.end(), [](Book a, Book b) { return a.author < b.author; });
        cout << "Books sorted by author.\n";
        break;
    case 3: // Sort by ISBN
        sort(books.begin(), books.end(), [](Book a, Book b) { return a.ISBN < b.ISBN; });
        cout << "Books sorted by ISBN.\n";
        break;
    default:
        cout << "Invalid criteria.\n";
    }
}
int main() {
    Library library;

    library.addBook();
    library.viewBooks();

    library.borrowBook("12345", "Alice");
    library.returnBook("12345");
    library.sortBooks(1); // Sort by title
    library.viewBooks();

    library.searchBook("67890");
    library.removeBook("12345");
    library.viewBooks();

    return 0;
}



/*

"Introduction to Algorithms", "Cormen", "67890"

*/