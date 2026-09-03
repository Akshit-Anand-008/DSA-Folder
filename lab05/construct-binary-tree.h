#pragma once
#include "common.h"

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;

    explicit TreeNode(int value) : value(value), left(nullptr), right(nullptr) {}
};

// Reconstructs the unique binary tree represented by preorder and inorder.
TreeNode* buildTree(const vector<int>& preorder, const vector<int>& inorder);

// Returns the values of the tree in left-right-root order.
vector<int> postorderTraversal(const TreeNode* root);
