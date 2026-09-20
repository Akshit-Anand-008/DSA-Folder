#include "common.h"
#include "task-scheduler.h"

int main(int argc, char** argv) {
    if (argc > 1) {
        if (freopen(argv[1], "r", stdin) == nullptr) // cin redirects to file argv[1]
        {
            std::cerr << "Error: Could not open input file " << argv[1] << std::endl;
            return 1;
        }
        // TODO : kdjf
    }

    int n, k;
    if (!(cin >> n >> k)) return 0;

    vector<Task> tasks;
    tasks.reserve(n);
    for (int i = 0; i < n; ++i) {
        int id, priority;
        cin >> id >> priority;
        tasks.emplace_back(id, priority);
    }

    vector<int> order = getExecutionOrder(tasks, k);
    for (int id : order) {
        cout << id << endl;
    }

    return 0;
}
