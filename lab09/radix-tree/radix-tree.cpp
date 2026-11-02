#include "radix-tree.h"

struct Node {
    bool end;
    std::map<string, Node*> edge;
    Node(bool b = false) : end(b) {}
};

int lgp(const string& s1, const string& s2) {
    int i = 0;
    int j = 0;
    while (s1[i] && s2[j] && s1[i] == s2[j]) {
        i++;
        j++;
    }
    return i;
}

void insert(const string& word) {
    // am I actually using the whole edge for comparing various nodes
    // no I just need the first char and then see how much match do I get
    // a map for chars and then
}

bool search(const string& word) {
    /* --- Start of student code, Don't Remove or edit these markers --- */
    // Code here

    /* --- End of student code, Don't Remove or edit these markers --- */
}

bool startsWith(const string& prefix) {
    /* --- Start of student code, Don't Remove or edit these markers --- */
    // Code here

    /* --- End of student code, Don't Remove or edit these markers --- */
}

bool remove(const string& word) {
    /* --- Start of student code, Don't Remove or edit these markers --- */
    // Code here

    /* --- End of student code, Don't Remove or edit these markers --- */
}
