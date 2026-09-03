#pragma once
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// A single base in the sequence, stored as one node of a singly linked list.
struct Node {
    char base;
    Node *next;
    Node(char b) : base(b), next(nullptr) {}
};
