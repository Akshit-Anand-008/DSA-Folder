#include "common.h"
#include "stable-rank.h"

int main(int argc, char** argv) {
    if (argc > 1) {
        if (freopen(argv[1], "r", stdin) == nullptr) // cin redirects to file argv[1]
        {
            std::cerr << "Error: Could not open input file " << argv[1] << std::endl;
            return 1;
        }
    }

    int n, k;
    if (!(cin >> n >> k)) return 0;

    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    vector<int> R = stableRank(A, k);

    for (int i = 0; i < n; ++i) {
        cout << R[i] << " \n"[i == n - 1];
    }
    if (n == 0) cout << endl;

    return 0;
}
