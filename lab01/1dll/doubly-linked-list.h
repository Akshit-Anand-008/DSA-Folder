#pragma once
#include "common.h"

struct node {
    int val;
    node *next, *prev;
};

class list {
private:
    node sentinel;  // sentinel.next is head, sentinel.prev is tail
    int sz;         // number of elements (does not count the sentinel)
    bool flipped;   // true => next and prev are to be read in the opposite sense
public:
    list() {
        sentinel.val = 0;
        sentinel.next = sentinel.prev = &sentinel;
        sz = 0;
        flipped = false;
    }
    node* end() { return &sentinel; }
    void insert_before(node* p, int v);
    void erase(node* p);
    list(const list&) = delete;
    list& operator=(const list&) = delete;

    ~list();
    node* begin();
    node* next(node* p);
    node* prev(node* p);
    int size() const;
    void reverse();
    void join(list& other);
    void print();
    node* find(int v);
};
