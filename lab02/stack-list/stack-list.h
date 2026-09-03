#pragma once
#include "common.h"

const int BLOCK_SIZE = 3;

struct stackBlock {
    char data[BLOCK_SIZE];
    int top_idx = 0;

    bool try_push(char x);
    bool pop(char& x);
    bool empty() const;
};

struct stackNode {
    stackBlock block;
    stackNode* below = nullptr;
};

class stackList {
private:
    stackNode* head;

public:
    stackList();
    ~stackList();

    bool empty() const;
    void push(char x);
    bool pop(char& x);
    void print_blocks() const;
};