#include "common.h"
#include "rebuild-bst.h"

static void print_level_order(Node *root) {
    if (root == nullptr) {
        cout << "\n";
        return;
    }
    vector<Node *> queue;
    queue.push_back(root);
    size_t head = 0;
    bool first = true;
    while (head < queue.size()) {
        Node *node = queue[head++];
        if (!first) cout << " ";
        cout << node->key;
        first = false;
        if (node->left != nullptr) queue.push_back(node->left);
        if (node->right != nullptr) queue.push_back(node->right);
    }
    cout << "\n";
}

static void free_tree(Node *root) {
    vector<Node *> stack;
    if (root != nullptr) stack.push_back(root);
    while (!stack.empty()) {
        Node *node = stack.back();
        stack.pop_back();
        if (node->left != nullptr) stack.push_back(node->left);
        if (node->right != nullptr) stack.push_back(node->right);
        delete node;
    }
}

int main(int argc, char **argv) {
    if (argc > 1) {
        if (freopen(argv[1], "r", stdin) == nullptr) {
            std::cerr << "Error: Could not open input file " << argv[1] << std::endl;
            return 1;
        }
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> postorder(n);
        for (int i = 0; i < n; i++) {
            cin >> postorder[i];
        }

        Node *root = build_bst_from_postorder(postorder);
        print_level_order(root);
        free_tree(root);
    }
    return 0;
}
