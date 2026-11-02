#pragma once
#include "common.h"

// Builds the cumulative count array C of size K+1, where C[v] equals the
// number of elements of A that are <= v, for every v in [0, K].
vector<int> buildCumulativeCount(const vector<int>& A, int K);

// Given the original array A and the cumulative count array C (as produced
// by buildCumulativeCount), scans A from right to left and hands out one
// position per value from C, so that ties are broken in favor of the
// element that appears earlier in A. Returns the resulting rank array R,
// where R[i] is the final position of A[i].
vector<int> placeRanks(const vector<int>& A, vector<int> C);

// Returns the stable rank array R, where R[i] is the 1-indexed position
// A[i] would occupy if A were sorted stably into non-decreasing order.
vector<int> stableRank(const vector<int>& A, int K);
