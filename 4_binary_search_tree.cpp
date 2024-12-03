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

int main() {
    BST bst;

    vector<Book> v;
    for (int i=0; i<5; i++) {
        Book tb;
        tb.get_book();
        v.push_back(tb);
        bst.insert(tb);
    }

    
    bst.printInOrder();
    bst.search("To-Kill-a-Mockingbird");

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
