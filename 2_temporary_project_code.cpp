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
    BST_node* insert(BST_node* rt, Book d) {
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
    void inOrder(BST_node* rt) {
        if (rt != nullptr) {
            inOrder(rt->left);
            rt->data.disp();
            inOrder(rt->right);
        }
    }
    BST_node* search(BST_node* rt, const string& title) const {
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
        cout << endl << endl;
        cout << "In-order traversal: " << endl; 
        inOrder(root);
        cout << endl;
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

class Quick_sort{
    public: 
    void sort(vector<Book> &b, int low, int high) {
        if (low > high) {
            return;
        }
        int p = partition(b, low, high);
        sort(b, low, p-1);
        sort(b, p+1, high);
    }
    int partition(vector<Book> &bk, int low, int high) {
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

class Library{ 
    private:
    vector<Book> books;
    BST bst;
    Stack st;
    public:
    void store_books(); 
    void view_books();
    void sort_by_ISBN();
    void sort_by_title();
    void search_book(string ttl);
    // void borrow_book(String ttl, string nm);
};

void Library :: store_books(){
    cout << "Enter the number of books to store: "; 
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        Book b;
        b.get_book();
        books.push_back(b);
        bst.insert(b);
    }
}

void Library :: view_books() {
    for (auto b: books) {
        b.disp();
    }
}

void Library :: sort_by_ISBN() {
    for (int i=0; i<books.size(); i++) {
        for (int j=1; j<books.size(); j++) {
            if (books[j-1].get_ISBN() > books[j].get_ISBN()) {
                swap(books[j-1], books[j]);
            }
        }
    }
}

void Library :: sort_by_title() {
    Quick_sort qs; 
    qs.sort(books, 0, books.size()-1); 
}

void Library :: search_book(string ttl) {
    bst.search(ttl);
}

// void borrow_book(String ttl, string nm) {
//     Book b;
//     for (int i=0; i<books.size(); i++) {
//         if (books[i].get_title() == ttl) {
//             b = books[i];
//             books.erase(books.begin()+i);
//         }
//     }
    
// }


int main() {
    Library lb;
    lb.store_books();
    // lb.view_books();

    lb.sort_by_title();
    cout << endl << endl;
    lb.view_books();

    cout << endl << endl;
    lb.search_book("To-Kill-a-Mockingbird");

    return 0;
}







































/*
5
To-Kill-a-Mockingbird       Harper-Lee              978-0-06-112008-4
1984                        George-Orwell           978-0-452-28423-4
The-Great-Gatsby            F-Scott-Fitzgerald      978-0-7432-7356-5
Pride-and-Prejudice         Jane-Austen             978-0-19-953556-9
The-Catcher-in-the-Rye      J.D.Salinger            978-0-316-76948-0



*/



/*


    Stack st;
    st.push("kamru");
    st.push("akib");
    st.push("sifat");
    st.push("fahian");

    while (!st.isEmpty()) {
        cout << st.top() << endl;
        st.pop();
    }

    Queue q;
    q.enqueue("kamru");
    q.enqueue("glib");
    q.enqueue("bivha");
    q.enqueue("bahar");
    q.traverse();
    cout << q.back() << endl;
    cout << q.front() << endl;
    

*/