#include "common.h"
#include "triage.h"
#define TOLERANCE 10

long long SealedCase::comparisons = 0;

SealedCase make_sealed(int value) { return SealedCase(value); }
int reveal(const SealedCase &c) { return c.value; }

static int ceil_log2(long long n) {
    int bits = 0;
    long long p = 1;
    while (p < n) {
        p *= 2;
        bits++;
    }
    return bits;
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
        int type, n;
        cin >> type >> n;

        vector<int> raw(n);
        vector<SealedCase> sealed;
        sealed.reserve(n);
        for (int i = 0; i < n; i++) {
            cin >> raw[i];
            sealed.push_back(make_sealed(raw[i]));
        }

        SealedCase::comparisons = 0;
        pair<SealedCase, SealedCase> result = (type == 1)
            ? find_first_and_last(sealed)
            : find_smallest_and_second_smallest(sealed);
        long long allowed = (type == 1)
            ? (3LL * n + 1) / 2 - 2
            : n + ceil_log2(n) - 2 + TOLERANCE;

        long long used = SealedCase::comparisons;
        if (used > allowed) {
            cout << "TOO MANY COMPARISONS: used " << used
                 << ", allowed " << allowed << " for n=" << n
                 << " (type " << type << ")\n";
            continue;
        }

        cout << reveal(result.first) << " " << reveal(result.second) << "\n";
    }
    return 0;
}
