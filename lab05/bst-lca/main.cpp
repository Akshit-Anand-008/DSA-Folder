#include "common.h"
#include "bst-lca.h"

int main(int argc, char** argv) {
    if (argc > 1) {
        if (freopen(argv[1], "r", stdin) == nullptr) // cin redirects to file argv[1]
        {
            std::cerr << "Error: Could not open input file " << argv[1] << std::endl;
            return 1;
        }
    }

    int n;
    if (!(cin >> n)) return 0;

    BST tree;
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        tree.insert(val);
    }

    int q;
    if (!(cin >> q)) return 0;

    for (int i = 0; i < q; ++i) {
        int u, v;
        cin >> u >> v;

        Node* lca = tree.findLCA(u, v);

        if (lca != nullptr) {
            cout << "LCA(" << u << ", " << v << ") = " << lca->val << endl;
        } else {
            cout << "LCA(" << u << ", " << v << ") = NOT FOUND" << endl;
        }
    }

    return 0;
}