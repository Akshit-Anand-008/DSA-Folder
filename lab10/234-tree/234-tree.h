#pragma once
#include "common.h"

// A node with d children holds d-1 keys in increasing order, d in {2, 3, 4}.
// The empty leaves are not stored, so a bottom-most node has no children.
struct Node {
    vector<int> keys;
    vector<Node*> children;
};

// u has 1 or 2 keys. Adds key to u. If right is not nullptr, it becomes the
// child just right of key.
void addKey(Node* u, int key, Node* right);

// u has 3 keys a < b < c. Keeps a and the first two children in u, moves c
// and the last two children to a new node, returns the new node, sets up = b.
Node* split(Node* u, int& up);

// Children i and i+1 of p hold one key in total. Replaces them and key i of
// p by one node.
void merge(Node* p, int i);

// Inserts key into the tree. root is nullptr when the tree is empty.
void insert(Node*& root, int key);

// Deletes key from the tree. key is in the tree.
void remove(Node*& root, int key);
