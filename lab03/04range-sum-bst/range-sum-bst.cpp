#include "range-sum-bst.h"

bool fun(int n, int low, int high){
    if(n>=low && n<=high){return true;}
    return false;
}

int Solution::rangeSumBST(Node* root, int low, int high){
    int ans=0;

    if(root==nullptr){return ans;}
    if(fun(root->val,low,high)){ans+=root->val;}

    if(root->right!=nullptr && root->right->val < low){ return ans; }
    if(root->left!=nullptr && root->left->val > high){ return ans; }

    ans+=rangeSumBST(root->right, low, high);
    ans+=rangeSumBST(root->left, low, high);

    return ans;
}
