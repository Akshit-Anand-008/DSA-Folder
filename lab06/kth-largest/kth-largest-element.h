#pragma once

#include "common.h"

// Returns the Kth largest element using a max-heap.
// Time: O(N + K log N)
// Auxiliary Space: O(N)
int kthLargestMaxHeap(const vector<int>& arr, int K);

// Returns the Kth largest element using a min-heap of size K.
// Time: O(N log K)
// Auxiliary Space: O(K)
int kthLargestMinHeap(const vector<int>& arr, int K);
