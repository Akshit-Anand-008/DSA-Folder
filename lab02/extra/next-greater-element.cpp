#include "next-greater-element.h"

std::vector<int> nextGreaterElement(const vector<int> &arr) {
    int len = arr.size();
    std::vector<int> ans(len, -1);
    std::stack<int> S;
    for(int i=len-1; i>=0; i--){
        int e = arr[i];
        while(!S.empty() && S.top() <= e){S.pop();} //before popping always check if the container is empty
        if(!S.empty()){ans[i]=S.top();}
        S.push(e);
    }
    return ans;
}
