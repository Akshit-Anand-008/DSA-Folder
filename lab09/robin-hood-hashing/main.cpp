#include <iostream>
#include <string>
#include "robin-hood-hashing.h"

using namespace std;

int main(int argc, char** argv) {
    if (argc > 1) {
        if (freopen(argv[1], "r", stdin) == nullptr) // cin redirects to file argv[1]
        {
            std::cerr << "Error: Could not open input file " << argv[1] << std::endl;
            return 1;
        }
    }
    int capacity;
    if (!(cin >> capacity) || capacity < 1 || capacity > 10000) {
        cerr << "Capacity must be between 1 and 10000\n";
        return 1;
    }
    HashTable table;
    initializeTable(table, capacity);

    string command;

    while (cin >> command) {
        // printf("===============\n");
        // std::cout << command << " ";
        if (command == "INSERT") {
            int key;
            if (!(cin >> key)) return 1;
            insertKey(table, key);
        } else if (command == "DELETE") {
            int key;
            if (!(cin >> key)) return 1;
            deleteKey(table, key);
        } else if (command == "SEARCH") {
            int key;
            if (!(cin >> key)) return 1;
            cout << searchKey(table, key) << '\n';
        } else if (command == "SIZE") {
            cout << table.size << '\n';
        } else if (command == "DISPLAY") {
            displayTable(table);
        } else if (command == "END") {
            break;
        } else {
            cout << "Invalid command\n";
        }
    }

    return 0;
}
