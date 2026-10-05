#include "contaminant.h"

bool match(vector<Node*>& S, const string& pattern){
    int len = pattern.size();
    int size = S.size();
    for (int i = 0; i < len; i++) {
        if(pattern[i] != S[size - len + i]->base){ return false; }
    }
    return true;
}

int recover_original(Node*& head, const string& pattern) {
    vector<Node*> S;
    int len = pattern.size();
    Node* ptr = head;
    while(ptr != nullptr){
        S.push_back(ptr);
        ptr = ptr ->next;
        while(S.size() >= len && match(S, pattern)){
            for (int i = 0; i < len; i++) {
                Node* last_ele = S[S.size()-1];
                delete last_ele;
                S.pop_back();
            }
        }
    }
    if(S.size() == 0){
        head = nullptr;
        return 0;
    }

    head = S[0];
    for (int i = 1; i < S.size(); i++) { S[i-1] -> next = S[i]; }
    S[S.size()-1]->next = nullptr;
    return S.size();
}
