#include "doubly-linked-list.h"

void list::insert_before(node* p, int v) {
    if (!flipped) {
        node* tmp = new node{v, p, p->prev};
        p->prev->next = tmp;
        p->prev = tmp;
    }
    else {
        node* tmp = new node{v, p->next, p};
        p->next->prev = tmp;
        p->next = tmp;
    }
    sz++;
}

void list::join(list& other) {
    if (this == &other) { return; }
    node* ptr = other.begin();
    while (ptr != other.end()) {
        insert_before(this->end(), ptr->val);
        sz++;
        erase(ptr);
        other.sz--;
        ptr = other.begin();
    }
}

void list::erase(node* p) {
    p->prev->next = p->next;
    p->next->prev = p->prev;
    delete p;
    sz--;
}

list::~list() {
    node* ptr = this->begin();
    while (ptr != this->end()) {
        erase(ptr);
        ptr = this->begin();
    }
}

node* list::begin() {

}

node* list::next(node* p) {}

node* list::prev(node* p) {}
// if next and prev are literally returning pointers, why aren't they assignable

int list::size() const { return sz; }

void list::reverse() {}

void list::print() {
    node* ptr = next(&sentinel);
    while (ptr != &sentinel) {
        cout << ptr->val << " ";
        ptr = next(ptr);
    }
    cout << endl;
}

node* list::find(int v) {
    node* ptr = next(&sentinel);
    while (ptr != &sentinel) {
        if (ptr->val == v) { return ptr; }
        ptr = next(ptr);
    }
    return &sentinel;
}
