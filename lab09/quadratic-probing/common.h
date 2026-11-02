#ifndef COMMON_H
#define COMMON_H

#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

enum SlotStatus {
    EMPTY = 0,
    OCCUPIED = 1,
    DELETED = 2
};

struct HashTable {
    int capacity = 0;
    std::vector<int> keys;
    std::vector<int> status;
};

#endif
