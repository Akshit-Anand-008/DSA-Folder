#include "merge-k-sorted.h"

std::priority_queue<Element, vector<Element>, greater<Element>> Q;
bool Element::operator>(const Element& other) const {
    if(this->val == other.val){
        return (this->list_idx > other.list_idx);
    }
    return (this->val > other.val);
}

// void fun(const vector<vector<int>>& lists,vector<int>& ans){
//     Element e = Q.top();
//     ans.push_back(e.val);
//     if(e.elem_idx + 1 < lists[e.list_idx].size()){
//         fun()
//     }
//     Q.pop();
// }

void qprint(std::priority_queue<Element, vector<Element>, greater<Element>> Q){
    while(!Q.empty()){
        std::cout << Q.top().val << " ";
        Q.pop();
    }
    std::cout  << std::endl;
}


vector<int> mergeKSorted(const vector<vector<int>>& lists) {
    std::vector<int> ans;
    // I just made q queue
    int size = 0;
    for (int i = 0; i < lists.size(); i++) {
        size+=lists[i].size();
    }
    for(int i=0; i<lists.size(); i++){
        if(lists[i].size()>0){
            Element *ele;
            ele = new Element(lists[i][0], i, 0);
            Q.push(*ele);
        }
    }
    // std::cout << "printing shit:  ";
    // qprint(Q);
    while(ans.size()<size){
        Element e = Q.top();
        ans.push_back(e.val);
        if((e.elem_idx + 1) < lists[e.list_idx].size()){
            Element *ele;
            ele = new Element(lists[e.list_idx][e.elem_idx+1], e.list_idx, e.elem_idx+1 );
            Q.push(*ele); 
        }
        Q.pop();
    }
    return ans;
}
