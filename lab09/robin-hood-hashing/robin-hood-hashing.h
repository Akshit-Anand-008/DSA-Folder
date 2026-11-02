#ifndef ROBIN_HOOD_HASHING_H
#define ROBIN_HOOD_HASHING_H

#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

// Slot states stored in HashTable::status.
const int EMPTY = 0;
const int OCCUPIED = 1;

struct HashTable {
    int capacity = 0;
    int size = 0;                 // number of OCCUPIED slots
    std::vector<int> keys;
    std::vector<int> status;
};

// ----------------------- YOUR TASK -----------------------
// Implemented in robin-hood-hashing.cpp.
void insertKey(HashTable &table, int key);
void deleteKey(HashTable &table, int key);

// ------------------- PROVIDED HELPERS --------------------

inline void initializeTable(HashTable &table, int capacity) {
    table.capacity = capacity;
    table.size = 0;
    table.keys.assign(capacity, 0);
    table.status.assign(capacity, EMPTY);
}

// Home slot of key: h(key) = ((key % M) + M) % M, in [0, M-1].
inline int hashFunction(int key, int capacity) {
    int result = key % capacity;
    return result < 0 ? result + capacity : result;
}

// Probe-sequence length (distance from home) of the key stored in the
// OCCUPIED slot `index`: (index - h(key) + M) % M. A key at its home has PSL 0.
inline int psl(const HashTable &table, int index) {
    const int home = hashFunction(table.keys[index], table.capacity);
    return (index - home + table.capacity) % table.capacity;
}

// Provided Robin Hood search. Returns the index of key, or -1.
// Probes linearly from the key's home slot. Stops at an EMPTY slot, or as
// soon as it meets a resident that is richer (smaller PSL) than the key
// would be at that slot: Robin Hood insertion guarantees the key cannot be
// any further along.
inline int searchKey(const HashTable &table, int key) {
    int index = hashFunction(key, table.capacity);
    for (int dist = 0; dist < table.capacity; ++dist) {
        if (table.status[index] == EMPTY) return -1;
        if (table.keys[index] == key) return index;
        if (psl(table, index) < dist) return -1;
        index = (index + 1) % table.capacity;
    }
    return -1;
}

inline void displayTable(const HashTable &table) {
    for (int i = 0; i < table.capacity; ++i) {
        std::cout << i << ": ";
        if (table.status[i] == EMPTY) std::cout << "EMPTY";
        else std::cout << table.keys[i] << " (" << psl(table, i) << ")";
        std::cout << '\n';
    }
}

#endif
