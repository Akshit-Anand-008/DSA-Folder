#pragma once
#include "common.h"

// Represents a candidate element from one of the K sorted lists.
struct Element {
    int val;
    int list_idx;
    int elem_idx;

    Element(int val, int list_idx, int elem_idx)
        : val(val), list_idx(list_idx), elem_idx(elem_idx) {}

    // Comparator used by priority_queue<Element, vector<Element>, greater<Element>>.
    // Must return true if this element has lower priority (larger value) than other.
    // what is the use of list_idx and elem_idx
    bool operator>(const Element& other) const;
};

// Merges K sorted vectors into a single sorted vector in O(N log K) time
// using an active min-heap of size at most K.
vector<int> mergeKSorted(const vector<vector<int>>& lists);
