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
    // Your code starts from here -- DO NOT EDIT ANYTHING ABOVE

    // Your code ends here -- DO NOT EDIT ANYTHING BELOW
}

void RollbackDSU::undo() {
    // Your code starts from here -- DO NOT EDIT ANYTHING ABOVE

    // Your code ends here -- DO NOT EDIT ANYTHING BELOW
}
