#include "search-replace.h"

// --- Helper Functions (Already Implemented, straight from Lecture 12) ---

tree::tree() : root(nullptr) {}

tree::~tree() {
    destroyAll();
}

void tree::destroyAll() {
    // Iterative so it doesn't blow the stack on a deeply skewed tree.
    vector<node *> stack;
    if (root != nullptr) stack.push_back(root);
    while (!stack.empty()) {
        node *p = stack.back();
        stack.pop_back();
        if (p->left != nullptr) stack.push_back(p->left);
        if (p->right != nullptr) stack.push_back(p->right);
        delete p;
    }
    root = nullptr;
}

node *&tree::where(node *p) {
    if (p == root) return root;
    return (p->parent->left == p) ? p->parent->left : p->parent->right;
}

void tree::detach(node *p) {
    node *&pp = where(p);
    if (!p->left || !p->right) { // at least one child slot is empty
        pp = p->left ? p->left : p->right;
        if (pp) pp->parent = p->parent;
        return;
    }
    node *q = minimum(p->right); // successor: q->left == nullptr
    detach(q);                    // so this recursive call hits the case above
    pp = q;
    p->left->parent = q; // p->left != nullptr
    if (p->right) p->right->parent = q; // detach(q) may have set p->right = nullptr
    q->left = p->left;
    q->right = p->right;
    q->parent = p->parent;
    p->left = p->right = p->parent = nullptr;
}

void tree::erase(node *p) {
    if (!p) return;
    detach(p);
    delete p;
}

node *tree::find(int key) const {
    node *curr = root;
    while (curr != nullptr && curr->key != key) {
        curr = (key < curr->key) ? curr->left : curr->right;
    }
    return curr;
}

void tree::insert(int v) {
    // search for the parent whose child the new node will be
    node *parent = nullptr;
    for (node *curr = root; curr != nullptr;) {
        if (curr->key == v) return; // already present -- ignore duplicates
        parent = curr;
        if (v < curr->key) curr = curr->left;
        else curr = curr->right;
    }
    // create and attach the new node
    node *newnode = new node(v, parent);
    if (parent == nullptr) root = newnode; // was an empty tree
    else if (v < parent->key) parent->left = newnode;
    else parent->right = newnode;
}

vector<int> tree::levelOrder() const {
    vector<int> result;
    vector<node *> queue;
    if (root != nullptr) queue.push_back(root);
    size_t head = 0;
    while (head < queue.size()) {
        node *p = queue[head++];
        result.push_back(p->key);
        if (p->left != nullptr) queue.push_back(p->left);
        if (p->right != nullptr) queue.push_back(p->right);
    }
    return result;
}

// --- Student Implementation Section ---

node* tree::minimum(node *p) {
    while (p->left) p = p->left;
    return p;
}

node* maximum(node *p) {
    while (p->right) p = p->right;
    return p;
}

void tree::searchReplace(int x, int y) {
    // storing the location of x in a pointer xptr
    node* xptr = find(x);

    // if x doesn't exit do nothing
    if(xptr == nullptr) { return; }

    // if y is same as x do nothing
    if(x==y) {return;}

    // if y already exists, simply remove x and then return
    if(find(y)!=nullptr){
        erase(xptr);
        return;
    }

    node* pred = nullptr;
    node* succ = nullptr;

    node* ptr = xptr;
    if(ptr->left){ pred = maximum(ptr->left); }
    else{
        node* pt = ptr->parent;
        while(pt!=nullptr) {
            if(ptr == pt->right){
                pred = pt;
                break;
            }
            ptr = pt;
            pt = ptr->parent;
        }
    }
    // what if none of them ever happens then pred will always be nullptr
    // same for succ

    ptr = xptr;
    if(ptr->right){ succ = minimum(ptr->right); }
    else{
        node* pt = ptr->parent;
        while(pt!=nullptr) {
            if(ptr == pt->left){
                succ = pt;
                break;
            }
            ptr = pt;
            pt = ptr->parent;
        }
    }

    if((succ==nullptr || y < succ->key) && (pred==nullptr || y > pred->key)){
        xptr->key = y;
    }
    else{
        erase(xptr);
        insert(y);
    }
    return;

}
