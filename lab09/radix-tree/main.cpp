#include "radix-tree.h"

int main(int argc, char** argv) {
    if (argc > 1) {
        if (freopen(argv[1], "r", stdin) == nullptr) {
            std::cerr << "Error: Could not open input file " << argv[1] << std::endl;
            return 1;
        }
    }

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int Q;
    if (!(cin >> Q)) return 0;

    for (int i = 0; i < Q; ++i) {
        char operation;
        string X;

        cin >> operation >> X;

        switch (operation) {
            case 'I':
                insert(X);
                break;

            case 'S':
                cout << (search(X) ? "YES" : "NO") << "\n";
                break;

            case 'P':
                cout << (startsWith(X) ? "YES" : "NO") << "\n";
                break;

            case 'D':
                cout << (remove(X) ? "DELETED" : "NOT FOUND") << "\n";
                break;

            default:
                cerr << "Error: Invalid operation " << operation << endl;
                return 1;
        }
    }

    return 0;
}
