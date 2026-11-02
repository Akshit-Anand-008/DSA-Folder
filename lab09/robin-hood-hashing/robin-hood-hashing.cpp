#include "robin-hood-hashing.h"

using namespace std;

void insertKey(HashTable &table, int key) {
    int cap = table.capacity;
    if(searchKey(table, key)!=-1){
        std::cout << "Duplicate" << std::endl;
        return;
    }
    if(cap == table.size){
        std::cout << "Insertion failed" << std::endl;
        return;
    }
    int idx = hashFunction(key, cap);
    int psl = 0;
    while(table.status[idx] == OCCUPIED){
        int resident = table.keys[idx];
        int respsl = (idx - hashFunction(resident, cap) + cap) % cap;
        // printf("idx:%i, key:%i, resident:%i\n",idx,key,resident);
        // printf("psl:%i, respsl:%i\n",psl,respsl);
        if(respsl < psl){
            // printf("keys swapped\n");
            table.keys[idx] = key;
            key = resident;
            psl = respsl;
        }
        idx = (idx + 1)%cap;
        psl++;
    }
    table.keys[idx] = key;
    table.status[idx] = OCCUPIED;
    table.size++;
    std::cout << "Inserted" << std::endl;
    // printf("-table-\n");
    // displayTable(table);
    // printf("-------\n");
    return;
}

void deleteKey(HashTable &table, int key) {
    int cap = table.capacity;
    int idx = searchKey(table, key);
    if(idx == -1){
        std::cout << "Not found" << std::endl;
        return;
    }
    table.status[idx] = EMPTY;
    int nextidx = (idx + 1)%cap;
    while( !table.status[nextidx] == EMPTY && !(hashFunction(table.keys[nextidx], cap) == nextidx)) {
        table.keys[idx] = table.keys[nextidx];
        table.status[nextidx] = EMPTY;
        table.status[idx] = OCCUPIED;
        idx = nextidx;
        nextidx = (idx + 1)%cap;
    }
    std::cout << "Deleted" << std::endl;
    table.size--;
    return;
}
