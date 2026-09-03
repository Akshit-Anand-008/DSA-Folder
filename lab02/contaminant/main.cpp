#include "common.h"
#include "contaminant.h"

// Your code starts from here -- DO NOT EDIT ANYTHING ABOVE
// Your code ends here -- DO NOT EDIT ANYTHING BELOW

int main(int argc, char **argv) {
    if (argc > 1) {
        if (freopen(argv[1], "r", stdin) == nullptr) // cin redirects to file argv[1]
        {
            std::cerr << "Error: Could not open input file " << argv[1] << std::endl;
            return 1;
        }
    }
    // Fast I/O is required for long sequences
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;

        Node *head = nullptr;
        Node *tail = nullptr;
        for (int i = 0; i < n; i++) {
            char c;
            cin >> c;
            Node *node = new Node(c);
            if (head == nullptr) {
                head = tail = node;
            } else {
                tail->next = node;
                tail = node;
            }
        }
        string pattern;
        cin >> pattern;

        recover_original(head, pattern);

        for (Node *cur = head; cur != nullptr; cur = cur->next) {
            cout << cur->base;
        }
        cout << "\n";

        // Free whatever remains of the recovered list before the next case.
        while (head != nullptr) {
            Node *next = head->next;
            delete head;
            head = next;
        }
    }
    return 0;
}
