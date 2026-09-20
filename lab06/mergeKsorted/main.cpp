#include "common.h"
#include "merge-k-sorted.h"

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

    int k;
    if (!(cin >> k)) return 0;

    vector<vector<int>> lists(k);
    for (int i = 0; i < k; ++i) {
        int sz;
        if (!(cin >> sz)) return 0;
        lists[i].resize(sz);
        for (int j = 0; j < sz; ++j) {
            cin >> lists[i][j];
        }
    }

    vector<int> merged = mergeKSorted(lists);

    for (size_t i = 0; i < merged.size(); ++i) {
        if (i > 0) cout << " ";
        cout << merged[i];
    }
    cout << "\n";

    return 0;
}
