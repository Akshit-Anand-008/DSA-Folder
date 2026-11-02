#include "common.h"
#include "234-tree.h"

// Prints the tree on one line, level by level from the root.
void printTree(Node* root) {
    if (root == nullptr) {
        cout << "EMPTY\n";
        return;
    }
    vector<Node*> level = {root};
    while (!level.empty()) {
        if (level[0] != root) cout << " | ";
        vector<Node*> next;
        for (int i = 0; i < (int)level.size(); i++) {
            if (i) cout << " ";
            cout << "[";
            for (int j = 0; j < (int)level[i]->keys.size(); j++) {
                if (j) cout << " ";
                cout << level[i]->keys[j];
            }
            cout << "]";
            for (Node* c : level[i]->children) next.push_back(c);
        }
        level = next;
    }
    cout << "\n";
}

// Frees every node of the tree.
void freeTree(Node* u) {
    for (Node* c : u->children) freeTree(c);
    delete u;
}

int main(int argc, char** argv) {
    if (argc > 1) {
        if (freopen(argv[1], "r", stdin) == nullptr) // cin redirects to file argv[1]
        {
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
        Node* root = nullptr;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            insert(root, x);
        }
        int m;
        cin >> m;
        for (int i = 0; i < m; i++) {
            int x;
            cin >> x;
            remove(root, x);
        }
        printTree(root);
        if (root != nullptr) freeTree(root);
    }
    return 0;
}
