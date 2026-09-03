#include "contaminant.h"

int recover_original(Node*& head, const string& pattern) {
    int len = pattern.size();
    vector<Node*> V;
    Node* ptr = head;
    while (ptr != nullptr) {
        Node* next_node = ptr->next;
        V.push_back(ptr);
        if (V.size() >= pattern.size()) {
            bool flag = true;
            int i = 0;
            int j = V.size() - pattern.size();
            while (i < pattern.size()) {
                if (pattern[i] != V[j]->base) {
                    flag = false;
                    break;
                }
                i++;
                j++;
            }
            if (flag) {
                for (int i = 0; i < pattern.size(); i++) {
                    delete V[V.size() - 1];
                    V.pop_back();
                }
            }
        }
        // printf("V.size():%zu\n", V.size());
        // printf("ptr->base:%c\n\n", ptr->base);
        ptr = next_node;
    }
    head = V[0];
    for (int i = 0; i < V.size() - 1; i++) { V[i]->next = V[i + 1]; }
    V[V.size() - 1]->next = nullptr;
    // printf("Vector V\n");
    return V.size();
}
