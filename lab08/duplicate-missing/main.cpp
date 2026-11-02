#include "common.h"
#include "duplicate-missing.h"
#include <cstdlib>
#include <new>

// Every heap allocation goes through here, so the driver can tell whether
// findDuplicateAndMissing used extra memory.
static size_t allocatedBytes = 0;

void* operator new(size_t size) {
    allocatedBytes += size;
    if (void* p = malloc(size)) return p;
    throw bad_alloc();
}
void operator delete(void* p) noexcept { free(p); }
void operator delete(void* p, size_t) noexcept { free(p); }

// Anything above this is more than O(1) extra space.
const size_t EXTRA_MEMORY_LIMIT = 1024;

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
        vector<int> A(n);
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }

        int duplicate = 0, missing = 0;
        size_t before = allocatedBytes;
        findDuplicateAndMissing(A, duplicate, missing);

        bool arranged = missing >= 1 && missing <= n && A[missing - 1] == duplicate;
        for (int i = 0; i < n && arranged; i++) {
            if (i != missing - 1 && A[i] != i + 1) arranged = false;
        }

        if (allocatedBytes - before > EXTRA_MEMORY_LIMIT) {
            cout << "EXTRA MEMORY USED\n";
        } else if (!arranged) {
            cout << "WRONG ARRANGEMENT\n";
        } else {
            cout << duplicate << " " << missing << "\n";
        }
    }
    return 0;
}
