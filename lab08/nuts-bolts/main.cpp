#include "common.h"
#include "nuts-bolts.h"

// The sizes stay in this file, so the only way to learn about them is tryFit.
static vector<int> nutSize, boltSize;

int tryFit(int nut, int bolt) {
    int a = nutSize.at(nut), b = boltSize.at(bolt);
    if (b < a) return -1;
    if (b > a) return 1;
    return 0;
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
        nutSize.assign(n, 0);
        boltSize.assign(n, 0);
        for (int i = 0; i < n; i++) cin >> nutSize[i];
        for (int i = 0; i < n; i++) cin >> boltSize[i];

        vector<int> nuts(n), bolts(n);
        for (int i = 0; i < n; i++) {
            nuts[i] = i;
            bolts[i] = i;
        }

        matchNutsAndBolts(nuts, bolts);

        // boltOf[x] is the bolt placed next to nut x, or -1 if there is none.
        vector<int> boltOf(n, -1);
        for (int i = 0; i < n && i < (int)nuts.size() && i < (int)bolts.size(); i++) {
            if (nuts[i] >= 0 && nuts[i] < n) boltOf[nuts[i]] = bolts[i];
        }
        for (int i = 0; i < n; i++) {
            if (i) cout << " ";
            cout << boltOf[i];
        }
        cout << "\n";
    }
    return 0;
}
