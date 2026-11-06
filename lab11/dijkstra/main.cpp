#include "common.h"
#include "dijkstra.h"

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

    // Section 1: commands for the IndexedMinHeap
    int h, hn;
    cin >> h >> hn;
    if (h > 0) {
        IndexedMinHeap heap(hn);
        while (h--) {
            char op;
            cin >> op;
            if (op == 'I' || op == 'D') {
                int v;
                Key k;
                cin >> v >> k.first >> k.second;
                if (op == 'I') heap.insert(v, k);
                else heap.decreaseKey(v, k);
            } else if (op == 'X') {
                auto [v, k] = heap.extractMin();
                cout << v << " " << k.first << " " << k.second << "\n";
            } else if (op == 'C') {
                int v;
                cin >> v;
                cout << (heap.contains(v) ? 1 : 0) << "\n";
            } else { // 'E'
                cout << (heap.empty() ? 1 : 0) << "\n";
            }
        }
    }

    // Section 2: graph test cases
    int t;
    cin >> t;
    while (t--) {
        int n, m, s;
        cin >> n >> m >> s;
        vector<vector<Edge>> adj(n);
        for (int i = 0; i < m; i++) {
            int u, v;
            long long w;
            cin >> u >> v >> w;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        ShortestPaths sp = dijkstra(adj, s);
        int q;
        cin >> q;
        while (q--) {
            int target;
            cin >> target;
            vector<int> path = restorePath(sp, s, target);
            if (path.empty()) {
                cout << target << " unreachable\n";
            } else {
                cout << target << " " << sp.dist[target] << " " << sp.hops[target] << ":";
                for (int v : path) cout << " " << v;
                cout << "\n";
            }
        }
        int a, b;
        cin >> a >> b;
        cout << "meet " << meetingPoint(adj, a, b) << "\n";
    }
    return 0;
}
