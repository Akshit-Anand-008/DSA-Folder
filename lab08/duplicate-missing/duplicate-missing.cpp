#include "duplicate-missing.h"

void findDuplicateAndMissing(vector<int>& A, int& duplicate, int& missing) {
    for (int i = 0; i < A.size(); i++) {
        int m = i;
        int idx = A[m] - 1;
        while (!(A[m] == A[idx])) {
            std::swap(A[m], A[idx]);
            idx = A[m] - 1;
        }
        // printf("arrangement\n");
        // for (int j : A) {
        //     std::cout << j << " ";
        // }
        // std::cout << std::endl;
        // printf("------\n");
    }
    for (int i = 0; i < A.size(); i++) {
        if (A[i] != i + 1) {
            missing = i + 1;
            duplicate = A[i];
        }
    }
    return;
}
