#pragma once
#include "common.h"

// A holds the numbers 1..N, except that one number is missing and another
// number appears twice. Moves every number k to index k-1, leaves the
// second copy of the duplicate at index missing-1, and reports both numbers.
void findDuplicateAndMissing(vector<int>& A, int& duplicate, int& missing);
