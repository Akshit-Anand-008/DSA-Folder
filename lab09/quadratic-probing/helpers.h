#ifndef QUADRATIC_PROBING_HELPERS_H
#define QUADRATIC_PROBING_HELPERS_H

#include "common.h"

// Implemented in quadratic-probing.cpp; used by the provided update helper.
int searchKey(const HashTable &table, int key);

inline void initializeTable(HashTable &table, int capacity) {
    table.capacity = capacity;
    table.keys.assign(capacity, 0);
    table.status.assign(capacity, EMPTY);
}

inline int hashFunction(int key, int capacity) {
    int result = key % capacity;
    return result < 0 ? result + capacity : result;
}

// Provided helper: replacement uses the student searchKey implementation.
inline void updateKey(HashTable &table, int oldKey, int newKey) {
    const int oldIndex = searchKey(table, oldKey);
    if (oldIndex == -1) {
        std::cout << "Not found\n";
        return;
    }
    if (oldKey == newKey) {
        std::cout << "Updated\n";
        return;
    }
    if (searchKey(table, newKey) != -1) {
        std::cout << "Duplicate\n";
        return;
    }
    const int h = hashFunction(newKey, table.capacity);
    for (int i = 0; i < table.capacity; ++i) {
        const int index = (h + i * i) % table.capacity;
        // The old slot becomes available when oldKey is removed.
        if (index == oldIndex || table.status[index] != OCCUPIED) {
            table.status[oldIndex] = DELETED;
            table.keys[index] = newKey;
            table.status[index] = OCCUPIED;
            std::cout << "Updated\n";
            return;
        }
    }
    std::cout << "Insertion failed\n";
}

inline void displayTable(const HashTable &table) {
    for (int i = 0; i < table.capacity; ++i) {
        std::cout << i << ": ";
        if (table.status[i] == EMPTY) std::cout << "EMPTY";
        else if (table.status[i] == DELETED) std::cout << "DELETED";
        else std::cout << table.keys[i];
        std::cout << '\n';
    }
}

#endif
