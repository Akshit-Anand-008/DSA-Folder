#include "rebuild-bst.h"
#include <climits>

Node* fun(const vector<int>& postorder, int st, int end){
    if(st>end){return nullptr;}
    Node* root = new Node(postorder[end]);
    int idx=st;
    while(postorder[idx] < root->key){idx++;}
    root->left = fun(postorder, st, idx-1);
    root->right = fun(postorder, idx, end-1);
    return root;
}

Node* build_bst_from_postorder(const vector<int> &postorder) {
    return fun(postorder, 0, postorder.size()-1);
}
