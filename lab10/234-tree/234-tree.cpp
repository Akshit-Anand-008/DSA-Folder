#include "234-tree.h"

// --- Helper Functions (Already Implemented) ---

// Index of the child of u whose range contains key.
static int childIndex(Node* u, int key) {
    int i = 0;
    while (i < (int)u->keys.size() && u->keys[i] < key) i++;
    return i;
}

// Puts key into the subtree of u. If u splits, returns true and sets up to the
// key that moves into the parent and right to the new node.
static bool insertBelow(Node* u, int key, int& up, Node*& right) {
    Node* keyRight = nullptr;
    if (!u->children.empty()) {
        int childUp;
        if (!insertBelow(u->children[childIndex(u, key)], key, childUp, keyRight)) return false;
        key = childUp;
    }
    if (u->keys.size() < 3) {
        addKey(u, key, keyRight);
        return false;
    }
    right = split(u, up);
    addKey(key < up ? u : right, key, keyRight);
    return true;
}

void insert(Node*& root, int key) {
    if (root == nullptr) {
        root = new Node;
        root->keys = {key};
        return;
    }
    int up;
    Node* right;
    if (insertBelow(root, key, up, right)) {
        Node* newRoot = new Node;
        newRoot->keys = {up};
        newRoot->children = {root, right};
        root = newRoot;
    }
}

// Child i of p has no keys and child i+1 has 2 or more. Key i of p moves down
// into child i, and the smallest key of child i+1 moves up to replace it.
static void borrowFromRight(Node* p, int i) {
    Node* u = p->children[i];
    Node* r = p->children[i + 1];
    u->keys.push_back(p->keys[i]);
    p->keys[i] = r->keys.front();
    r->keys.erase(r->keys.begin());
    if (!r->children.empty()) {
        u->children.push_back(r->children.front());
        r->children.erase(r->children.begin());
    }
}

// Child i of p has no keys and child i-1 has 2 or more. Key i-1 of p moves
// down into child i, and the largest key of child i-1 moves up to replace it.
static void borrowFromLeft(Node* p, int i) {
    Node* u = p->children[i];
    Node* l = p->children[i - 1];
    u->keys.insert(u->keys.begin(), p->keys[i - 1]);
    p->keys[i - 1] = l->keys.back();
    l->keys.pop_back();
    if (!l->children.empty()) {
        u->children.insert(u->children.begin(), l->children.back());
        l->children.pop_back();
    }
}

// Child i of p has no keys. Fixes it with the first rule that applies.
static void repair(Node* p, int i) {
    Node* l = i > 0 ? p->children[i - 1] : nullptr;
    Node* r = i + 1 < (int)p->children.size() ? p->children[i + 1] : nullptr;
    if (r != nullptr && r->keys.size() >= 2)
        borrowFromRight(p, i);
    else if (l != nullptr && l->keys.size() >= 2)
        borrowFromLeft(p, i);
    else if (r != nullptr)
        merge(p, i);
    else
        merge(p, i - 1);
}

// Deletes key from the subtree of u. Returns true if u is left with no keys.
static bool removeBelow(Node* u, int key) {
    int i = childIndex(u, key);
    if (u->children.empty()) {
        u->keys.erase(u->keys.begin() + i);
        return u->keys.empty();
    }
    if (i < (int)u->keys.size() && u->keys[i] == key) {
        // Swap in the successor, then delete the successor below.
        Node* s = u->children[i + 1];
        while (!s->children.empty()) s = s->children[0];
        key = u->keys[i] = s->keys[0];
        i++;
    }
    if (removeBelow(u->children[i], key)) repair(u, i);
    return u->keys.empty();
}

void remove(Node*& root, int key) {
    if (removeBelow(root, key)) {
        Node* old = root;
        root = old->children.empty() ? nullptr : old->children[0];
        delete old;
    }
}

// --- Student Implementation Section ---

void addKey(Node* u, int key, Node* right) {
    // Your code starts from here -- DO NOT EDIT ANYTHING ABOVE

    // Your code ends here -- DO NOT EDIT ANYTHING BELOW
}

Node* split(Node* u, int& up) {
    // Your code starts from here -- DO NOT EDIT ANYTHING ABOVE

    // Your code ends here -- DO NOT EDIT ANYTHING BELOW
}

void merge(Node* p, int i) {
    // Your code starts from here -- DO NOT EDIT ANYTHING ABOVE

    // Your code ends here -- DO NOT EDIT ANYTHING BELOW
}
