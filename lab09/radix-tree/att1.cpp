#include "radix-tree.h"

// I need to make my own radix tree in here and that's why I was given
// this empty space

struct node {
    bool end;
    int noc;
    std::vector<node*> vec;
    // node* parent;
    node* last;
    node(node* last = nullptr) : end(false), noc(0) { vec.resize(26, nullptr); }
    // Do I need
    // the initialising list and then assigning are 2 different things
    // now I have a vector of size 26
    // I don't need to store key/char for each
    // as I already have 26 pointers int the parent node to find out which char it is
};

node* root = new node;

void insert(const string& word) {
    // Keep going from the root
    root->last = root;
    node* ptr = root;
    for (char c : word) {
        if (ptr->vec[c - 'a'] == nullptr) {
            node* boy = new node();
            ptr->noc++;
            ptr->end = false;
            if (ptr->noc > 1) {
                boy->last = ptr;
            } else {
                boy->last = ptr->last;
            }
            ptr->vec[c - 'a'] = boy;
        }
        ptr = ptr->vec[c - 'a'];
    }
    ptr->end = true;
    // I guess this is inserted now.
    // this will do the insertion job for me.
}
// time for searching now

bool search(const string& word) {
    node* ptr = root;
    for (char c : word) {
        if (ptr->end || ptr->vec[c - 'a'] == nullptr) {
            return false;
        }
        ptr = ptr->vec[c - 'a'];
    }
    return ptr->end;
}

bool startsWith(const string& prefix) {
    node* ptr = root;
    for (char c : prefix) {
        if (ptr->end || ptr->vec[c - 'a'] == nullptr) {
            return false;
        }
        ptr = ptr->vec[c - 'a'];
    }
    return true;
}

bool remove(const string& word) {
    if (!search(word)) {
        return false;
    }
    node* ptr = root;
    for (char c : word) {
        if (ptr->vec[c - 'a'] == nullptr) {
            return false;
        }
        ptr = ptr->vec[c - 'a'];
    }
    node* man = ptr->last;
    man->end = true;
    return true;
}

// First implement a trie
// and then we will implement radix tree
