#pragma once
#include "common.h"

struct Record {
    int child;      // root that was attached under `parent`
    int parent;     // root that `child` was attached under
    int child_val;  // value of A[child] just before the merge (i.e. -size of child's tree)
    // If the call merged nothing: child == parent (the common root) and child_val == 0.
};

class RollbackDSU {
public:
    explicit RollbackDSU(int n);

    int find(int x) const;

    // Returns true if two different sets were merged, false if x and y were
    // already in the same set.
    bool unite(int x, int y);

    void undo();

    int size_of(int x) const;

private:
    vector<int> A;            // A[i] >= 0: parent of i.  A[i] < 0: i is a root, set size = -A[i]
    vector<Record> history;   // the undo stack
};
