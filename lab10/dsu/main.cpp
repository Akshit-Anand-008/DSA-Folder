#include "common.h"
#include "dsu.h"

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
        int n, q;
        cin >> n >> q;
        RollbackDSU dsu(n);
        while (q--) {
            string op;
            cin >> op;
            if (op == "UNITE") {
                int x, y;
                cin >> x >> y;
                cout << (dsu.unite(x, y) ? 1 : 0) << "\n";
            } else if (op == "UNDO") {
                dsu.undo();
            } else if (op == "FIND") {
                int x;
                cin >> x;
                cout << dsu.find(x) << "\n";
            } else if (op == "SIZE") {
                int x;
                cin >> x;
                cout << dsu.size_of(x) << "\n";
            }
        }
    }
    return 0;
}
