#include "next-greater-element.h"

vector<int> nextGreaterElement(const vector<int>& arr) {
    stack<int> S;
    vector<int> V(arr.size());
    int idx = arr.size() - 1;

    while (idx >= 0) {
        if (S.empty()) {
            V[idx] = -1;
            S.push(arr[idx]);
            idx--;
        }
        else {
            if (arr[idx] < S.top()) {
                V[idx] = S.top();
                S.push(arr[idx]);
                idx--;
            }
            else { S.pop(); }
        }
    }

    return V;
}
