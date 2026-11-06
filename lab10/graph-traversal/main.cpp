#include "common.h"
#include "graph-traversal.h"

static void printLine(const vector<int>& v) {
    for (int i = 0; i < (int)v.size(); i++) {
        if (i) cout << " ";
        cout << v[i];
    }
    cout << "\n";
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
        int n, m, start;
        cin >> n >> m >> start;
        vector<vector<int>> adj(n);
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> stackPushed, stackVisited;
        traverseStack(adj, start, stackPushed, stackVisited);
        printLine(stackPushed);
        printLine(stackVisited);

        vector<int> queuePushed, queueVisited;
        traverseQueue(adj, start, queuePushed, queueVisited);
        printLine(queuePushed);
        printLine(queueVisited);
    }
    return 0;
}
