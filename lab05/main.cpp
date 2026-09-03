#include "common.h"
#include "construct-binary-tree.h"

namespace {

void collectPreorder(const TreeNode* root, vector<int>& values) {
    if (root == nullptr) {
        return;
    }
    values.push_back(root->value);
    collectPreorder(root->left, values);
    collectPreorder(root->right, values);
}

void collectInorder(const TreeNode* root, vector<int>& values) {
    if (root == nullptr) {
        return;
    }
    collectInorder(root->left, values);
    values.push_back(root->value);
    collectInorder(root->right, values);
}

void deleteTree(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

} // namespace

int main(int argc, char** argv) {
    if (argc > 1) {
        if (freopen(argv[1], "r", stdin) == nullptr) // cin redirects to file argv[1]
        {
            std::cerr << "Error: Could not open input file " << argv[1] << std::endl;
            return 1;
        }
    }

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;

        vector<int> preorder(n);
        vector<int> inorder(n);
        for (int& value : preorder) {
            cin >> value;
        }
        for (int& value : inorder) {
            cin >> value;
        }

        TreeNode* root = buildTree(preorder, inorder);

        vector<int> actualPreorder;
        vector<int> actualInorder;
        collectPreorder(root, actualPreorder);
        collectInorder(root, actualInorder);

        if (actualPreorder != preorder || actualInorder != inorder) {
            cout << "invalid\n";
            deleteTree(root);
            continue;
        }

        vector<int> postorder = postorderTraversal(root);
        for (int i = 0; i < static_cast<int>(postorder.size()); i++) {
            if (i > 0) {
                cout << ' ';
            }
            cout << postorder[i];
        }
        cout << '\n';

        deleteTree(root);
    }
    return 0;
}
