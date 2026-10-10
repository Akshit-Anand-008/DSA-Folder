#include "largest-rectangle.h"

long long largestRectangleBruteForce(const vector<int> &heights) {
    vector<int> v = {0};
    for (const int& i : heights) {v.push_back(i);}
    v.push_back(0);
    long long ans = 0;
    int len = v.size();
    for (int i = 1; i < len-1; i++) {
        int lt = i;
        int rt = i;
        while(lt >= 0){ 
            if(v[lt] < v[i]){ break; }
            lt--;
        }
        while(rt < len){
            if(v[rt]<v[i]){break;} 
            rt++;
        }
        long long area = (rt - lt - 1) * v[i];
        ans = max(area,ans);
    }
    return ans;
}

long long largestRectangleOptimal(const vector<int> &heights) {
    vector<int> v = {0};
    for (const int& i : heights) {v.push_back(i);}
    v.push_back(0);

    stack<int> s;
    s.push(0);
    long long area = 0;
    long long ans = 0;
    for (int i = 1; i < v.size(); i++) {
        while(!s.empty() && (v[s.top()] > v[i])){
            int top = s.top();
            s.pop();
            int lt = s.top();
            int rt = i;
            area = (rt - lt - 1)*v[top];
            ans = max(ans, area);
        }
        s.push(i);
    }
    return ans;
}
