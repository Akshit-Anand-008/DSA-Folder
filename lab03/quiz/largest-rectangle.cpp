#include "largest-rectangle.h"

long long largestRectangleBruteForce(const vector<int> &heights) {
    // printf("brute\n");
    long long ans = 0;
    int len = heights.size();
    for(int i=0; i<len; i++){
        int left = i;
        int right = i;
        while(left >= 1 && heights[left-1] >= heights[i]){ left--; }
        while(right < len-1 && heights[right+1] >= heights[i]){ right++; }
        long long area = heights[i]*(right - left + 1);
        ans = max(area, ans);
        // printf("area:%i\n",area);
    }
    return ans;
}

long long largestRectangleOptimal(const vector<int> &heights) {
    // printf("op\n");
    int len = heights.size();
    long long ans = 0;
    std::stack<int> S;
    for (int i = 0; i < len; i++) { 
        while(!S.empty() && heights[S.top()] >= heights[i]){ 
            int el = S.top();
            S.pop();
            int left = S.empty() ? -1 : S.top();
            long long area = heights[el]*(i - left -1);
            // printf("area:%i\n",area);
            ans = max(area, ans);
        }
        S.push(i);
    }
    // this won'r work as well as this assumes that the elements are adjacent
    while(!S.empty()){
        int el = S.top();
        S.pop();
        int left = S.empty() ? -1 : S.top();
        long long area = heights[el]*(len - left -1);
        // printf("area:%i\n",area);
        ans = max(area, ans);
    }
    return ans;
}
