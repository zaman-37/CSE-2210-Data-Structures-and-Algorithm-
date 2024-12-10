// Example of binary tree traversal... ... ... ... ... 

#include <bits/stdc++.h>
using namespace std;

class node{
    public: 
    node *left;
    int info;
    node *right;
    node(int a) : left(nullptr), info(a), right(nullptr){}
};

node* insert(node *root, int a) {
    node *ptr = new node(a);
    if (root->left == nullptr) {
        root->left = ptr;
    }
    else {
        root->right = ptr;
    }
    return ptr;
}


void inorder(node *root) {
    if (root == nullptr) {
        return;
    }
    inorder(root->left);
    cout << root->info << " ";
    inorder(root->right);
}

void preorder(node *root) {
    if (root == nullptr) {
        return;
    }
    cout << root->info << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(node *root) {
    if (root == nullptr) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->info << " ";
}

int main() {
    node *root = new node(1);
    node *rt1 = insert(root, 12);
    node *rt2 = insert(root, 9);
    node* rt3 = insert(rt1, 5);
    node* rt4 = insert(rt1, 6);

    cout << "inorder: ";
    inorder(root);
    cout << endl;
    
    cout << "preorder: ";
    preorder(root);
    cout << endl;

    cout << "postorder: ";
    postorder(root);
    cout << endl;

    return 0;
}