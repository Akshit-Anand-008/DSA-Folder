#include "dsu.h"

RollbackDSU::RollbackDSU(int n) : A(n, -1) {}

bool RollbackDSU::unite(int x, int y) {
    int a = find(x), b = find(y);
    if (a == b) {
        history.push_back({a, a, 0});
        return false;
    }
    if (A[a] > A[b]) swap(a, b);
    history.push_back({b, a, A[b]});
    A[a] += A[b];
    A[b] = a;
    return true;
}

int RollbackDSU::size_of(int x) const { return -A[find(x)]; }

int RollbackDSU::find(int x) const {
    int i = x;
    while (A[i] >= 0){ i = A[i]; }
    return i;
}

void RollbackDSU::undo() {
    Record last = history[history.size()-1];
    history.pop_back();
    int b = last.child;
    int a = last.parent;
    int v = last.child_val;
    if(a == b){ return; }
    A[a] -= v;
    A[b] = v;
    return;
}
