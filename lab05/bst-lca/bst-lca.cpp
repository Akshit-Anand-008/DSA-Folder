#include "bst-lca.h"

// --- Helper Functions (Already Implemented) ---

// Constructs an empty BST.
BST::BST() : root(nullptr) {}

// Destructor: frees all nodes in the tree.
BST::~BST() {
    destroyTree(root);
}

// Recursively frees every node in the subtree rooted at `node`.
void BST::destroyTree(Node* node) {
    if (node != nullptr) {
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }
}

// --- Student Implementation Section ---

void BST::insert(int value) {
    if (root == nullptr){
        Node* shoot = new Node(value);
        this->root = shoot;
        return;
    }
    Node* ptr = root;
    Node* parent = nullptr;
    while(ptr != nullptr){
        parent = ptr; 
        if(value == ptr->val){ return; }
        else if(value < ptr->val){ ptr = ptr->left; }
        else{ ptr = ptr->right; }
    }
    Node* temp = new Node(value);
    if(value < parent->val){ parent->left = temp; }
    else{ parent->right = temp; }
    return;
}

Node* BST::findLCA(int u, int v) const {
    Node* ptr = this->root;
    while(true){
        int val = ptr->val;
        if(u<val && v<val){ ptr = ptr->left; }
        else if(u>val && v>val){ ptr = ptr->right; }
        else{ return ptr; }
    }
    return ptr;
}
