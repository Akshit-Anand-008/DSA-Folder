#include "doubly-linked-list.h"

// ============================================================================
// GIVEN -- do not edit. exanple given to show how to
// maintain sz and to respect the flipped flag. Read them: they show exactly
// what "incorporate the flag" means, and the functions you write must follow
// the same convention.
// ============================================================================

void list::insert_before(node* p, int v) {
    if (!flipped) {
        // logical order == physical order: put the new node between
        // p->prev and p, exactly as on the slide.
        node* tmp = new node{v, p, p->prev};
        p->prev->next = tmp;
        p->prev = tmp;
    } else {
        // logical order is reversed: "just before p" logically means
        // "just after p" physically.
        node* tmp = new node{v, p->next, p};
        p->next->prev = tmp;
        p->next = tmp;
    }
    sz++;
}

void list::erase(node* p) {
    // Unlinking is symmetric, so this needs no flag test: whichever way the
    // list is being read, p's two physical neighbours become each other's.
    p->prev->next = p->next;
    p->next->prev = p->prev;
    delete p;
    sz--;
}

// ============================================================================
// YOUR CODE -- implement each body between its two marker comments.
// ============================================================================

list::~list() {
    return;
}

node* list::begin() {
    if(this->sz == 0){return this->end();}
    return this->sentinel.next;
}

// this gives the value of the pointer and not
node* list::next(node* p) {
    return !(this->flipped) ? p->next : p->prev;
}

node* list::prev(node* p) {
    return !(this->flipped) ? p->prev : p->next;
}

int list::size() const {
    return this->sz;
}

void list::reverse() {
    this->flipped = !this->flipped;
}

void list::join(list& other) {
    if(this == &other){return;}
    if(other.sz == 0){return;}

    node* ts = &(this->sentinel);
    node* os = &(other.sentinel);

    node* ptr = other.begin();
    while(ptr != other.end()){
        node* nptr = other.next(ptr);
        node* tt = this->prev(ts);

        if(!(this->flipped)){
            tt -> next = ptr;
            ptr -> prev = tt;

            ptr -> next = ts;
            ts -> prev = ptr;
        }
        else if(this->flipped){
            tt -> prev = ptr;
            ptr -> next = tt;

            ptr -> prev = ts;
            ts -> next = ptr;
        }

        ptr = nptr;
    }

    // changing sizes and making other empty
    this->sz += other.sz;
    other.sz = 0;
    os->next = os;
    os->prev = os;
}

void list::print() {
    node* ts = &(this->sentinel);
    node* ptr = this->begin();
    while(ptr!=this->end()){
        std::cout << ptr->val << " ";
        ptr = this->next(ptr);
    }
    std::cout << std::endl;
}

node* list::find(int v) {
    node* ts = &(this->sentinel);
    node* ptr = this->begin();
    while(ptr!=ts){
        if(ptr->val == v){ return ptr; }
        ptr = this->next(ptr);
    }
    return this->end();
}
