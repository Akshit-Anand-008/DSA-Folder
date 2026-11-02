#include "quadratic-probing.h"

int searchKey(const HashTable& table, int key) {
    int cap = table.capacity;
    int ogidx = hashFunction(key, cap);
    for (int i = 0; i < cap; i++) {
        int idx = (ogidx + i * i) % cap;
        if (table.status[idx] == EMPTY) {
            return -1;
        }
        if (table.status[idx] == OCCUPIED && table.keys[idx] == key) {
            return idx;
        }
    }
    return -1;  // Fallback for the incomplete student template.
}

void insertKey(HashTable& table, int key) {
    if (searchKey(table, key) != -1) {
        std::cout << "Duplicate" << std::endl;
        return;
    }
    int cap = table.capacity;
    int ogidx = hashFunction(key, cap);
    for (int i = 0; i < cap; i++) {
        int idx = (ogidx + i * i) % cap;
        if (table.status[idx] != OCCUPIED) {
            table.keys[idx] = key;
            table.status[idx] = OCCUPIED;
            std::cout << "Inserted" << std::endl;
            return;
        }
    }
    std::cout << "Insertion failed" << std::endl;
    return;
}

void deleteKey(HashTable& table, int key) {
    int idx = searchKey(table, key);
    if (idx == -1) {
        std::cout << "Not found" << std::endl;
        return;
    }
    table.status[idx] = DELETED;
    std::cout << "Deleted" << std::endl;
    return;
}
