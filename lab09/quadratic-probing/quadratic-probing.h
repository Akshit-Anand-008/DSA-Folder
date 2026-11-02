#ifndef QUADRATIC_PROBING_H
#define QUADRATIC_PROBING_H

#include "common.h"

int searchKey(const HashTable& table, int key);
void insertKey(HashTable& table, int key);
void deleteKey(HashTable& table, int key);

#include "helpers.h"

#endif
