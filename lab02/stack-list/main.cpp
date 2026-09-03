#include "stack-list.h"

int main(int argc, char** argv) {
    if (argc > 1) {
        if (freopen(argv[1], "r", stdin) == nullptr) {
            std::cerr << "Error: Could not open input file " << argv[1] << std::endl;
            return 1;
        }
    }

    int n;
    if (!(cin >> n)) return 0;

    stackList list;
    for (int i = 0; i < n; i++) {
        string op;
        cin >> op;

        if (op == "PUSH") {
            char c;
            cin >> c;
            list.push(c);
            cout << "PUSH " << c << " -> ";
        }
        else if (op == "POP") {
            char c;
            bool success = list.pop(c);
            if (success) { cout << "POP " << c << "  -> "; }
            else { cout << "POP NONE -> "; }
        }
        list.print_blocks();
    }

    return 0;
}
