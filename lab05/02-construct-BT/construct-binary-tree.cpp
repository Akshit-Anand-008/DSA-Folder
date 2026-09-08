#include "construct-binary-tree.h"

unordered_map<int,int> M;

TreeNode* constructTree(const vector<int>& preorder, const vector<int>& inorder, int& preidx, int st, int end) {
    if(st > end) { return nullptr; }
    int val = preorder[preidx];
    preidx++;
    int idx = M[val];
    TreeNode* root = new TreeNode(val);
    root->left = constructTree(preorder,inorder, preidx, st,  idx-1);
    root->right= constructTree(preorder,inorder, preidx, idx+1, end);
    return root;
}

TreeNode* buildTree(const vector<int>& preorder, const vector<int>& inorder) {
    int preidx=0;
    for (int i = 0; i < inorder.size(); i++) { M[inorder[i]] = i; }
    return constructTree(preorder, inorder, preidx, 0, inorder.size()-1);
}

void printer(const TreeNode* root, vector<int>& ans) {
    if(root==nullptr){return;}
    if(root->left){ printer(root->left, ans); }
    if(root->right){ printer(root->right, ans); }
    ans.push_back(root->value);
    return;
}

vector<int> postorderTraversal(const TreeNode* root) {
    vector<int> ans;
    if(root){printer(root, ans);}
    return ans;
}
