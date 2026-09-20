#pragma once
#include "common.h"

struct Node {
    int val;
    Node* left;
    Node* right;

    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

class BST {
private:
    Node* root;

    // Helper for destructor
    void destroyTree(Node* node);

public:
    BST();
    ~BST();

    // Inserts a new value into the BST
    void insert(int value);

    // Finds the Lowest Common Ancestor of nodes with values u and v
    Node* findLCA(int u, int v) const;
};