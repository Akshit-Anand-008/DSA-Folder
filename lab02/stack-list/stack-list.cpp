#include "stack-list.h"

// --- Helper Functions (Already Implemented) ---

// Attempts to push an element into the block; returns false if the block is full.
bool stackBlock::try_push(char x) {
    if (top_idx < BLOCK_SIZE) {
        data[top_idx++] = x;
        return true;
    }
    return false;
}

// Attempts to pop the top element from the block into 'x'; returns false if the block is empty.
bool stackBlock::pop(char& x) {
    if (top_idx > 0) {
        x = data[--top_idx];
        return true;
    }
    return false;
}

// Checks if the current block contains zero elements.
bool stackBlock::empty() const { return top_idx == 0; }

// Initializes an empty stack list with a null head pointer.
stackList::stackList() { head = nullptr; }
// a constructor don't usually just uses memory

// In any question first read what the main is doing what the constructor is doing and if
// you are accessing valid memory

// Iterates through the linked list to safely delete all dynamically allocated stack nodes.
stackList::~stackList() {
    stackNode* curr = head;
    while (curr != nullptr) {
        stackNode* next = curr->below;
        delete curr;
        curr = next;
    }
}

// Checks if the entire stack list is empty, accounting for a potentially retained empty head block.
bool stackList::empty() const {
    if (head == nullptr) return true;
    if (head->block.empty() && head->below == nullptr) return true;
    return false;
}

// Traverses the list to print the total block count and the current number of elements in each block.
void stackList::print_blocks() const {
    stackNode* curr = head;
    int count = 0;
    while (curr) {
        count++;
        curr = curr->below;
    }

    cout << "Blocks: " << count << " | ";
    curr = head;
    while (curr) {
        cout << "[" << curr->block.top_idx << "] ";
        curr = curr->below;
    }
    cout << endl;
}

// --- Student Implementation Section ---

void stackList::push(char x) {
    if (head == nullptr) { head = new stackNode; }
    // what should I do when I try to push a value on a nullptr
    // should I create a new stack r=or just return
    if (head->block.empty()) {
        if (head->below == nullptr) {
            head->block.try_push(x);
            return;
        }
        if (!head->below->block.try_push(x)) { head->block.try_push(x); }
    }
    else {
        if (!head->block.try_push(x)) {
            stackNode* tmp = new stackNode;
            tmp->block.try_push(x);
            tmp->below = head;
            head = tmp;
        }
    }
}

bool stackList::pop(char& x) {
    if (head == nullptr) { return false; }
    if (head->block.empty()) {
        if (head->below == nullptr) { return false; }
        head->below->block.pop(x);
        if (head->below->block.empty()) {
            stackNode* tmp = head->below;
            delete head;
            head = tmp;
        }
    }
    else { head->block.pop(x); }
    return true;
}
