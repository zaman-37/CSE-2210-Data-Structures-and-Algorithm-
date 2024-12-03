#include <bits/stdc++.h>
using namespace std;

class Node{
    public: 
    int data;
    Node *left;
    Node *right;
    Node(int data){
        this->data = data;
        left = right = NULL;
    }
};

void inorderTraversal (Node *node) { // inorder traversal
    if (node == NULL) 
        return;

    inorderTraversal(node->left);
    cout << node->data << " ";
    inorderTraversal(node->right);
}

void preorder(Node *node) { // preorder traversal
    if (node == NULL) 
        return;

    cout << node->data << " ";
    preorder(node->left);
    preorder(node->right);
}

void postorder (Node *node) { // postorder traversal
    if (node == NULL)
        return;

    postorder(node->left);
    postorder(node->right);
    cout << node->data << " ";
}


int main() {
    Node* root=new Node(1);
    root->left = new Node(12);
    root->right = new Node(9);
    root->left->left = new Node(5);
    root->left->right = new Node(6);

    cout << "Inorder: ";
    inorderTraversal(root);
    cout << endl;

    cout << "Preorder: ";
    preorder(root);
    cout << endl;
    
    cout << "Postorder: ";
    postorder(root);
    cout << endl;

    return 0;
}