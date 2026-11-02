#include "stable-rank.h"

// --- Helper Functions (Already Implemented) ---

// Entry point: computes the cumulative counts, then places ranks with them.
vector<int> stableRank(const vector<int>& A, int K) {
    vector<int> C = buildCumulativeCount(A, K);
    return placeRanks(A, C);
}

// --- Student Implementation Section ---

// TODO: Count how many times each value in [0, K] occurs in A, then
// prefix-sum those counts so that C[v] = number of elements <= v.
vector<int> buildCumulativeCount(const vector<int>& A, int K) {
    vector<int> count(K + 1, 0);
    for (int i : A) {
        count[i]++;
    }
    for (int i = 1; i < K + 1; i++) {
        count[i] += count[i - 1];
    }
    return count;
}

// TODO: Walk A from right to left. Each A[i] claims position C[A[i]] and
// then decrements C[A[i]], so the next (earlier) occurrence of the same
// value claims the position just before it -- this is what keeps ties
// broken in favor of earlier indices.
vector<int> placeRanks(const vector<int>& A, vector<int> C) {
    int i = A.size() - 1;
    for (int i = C.size() - 1; i > 0; i--) {
        A[i] =
    }
}
