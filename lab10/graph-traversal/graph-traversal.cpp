#include "graph-traversal.h"

// --- Your Task ---
// Pseudo code
// frontier.insert(s);
// discovered(s) = true;
// while(!frontier.empty()){
//  frontier.extract;
//  for
// }

void traverseStack(const vector<vector<int>>& adj, int start, vector<int>& pushed, vector<int>& visited) {
    int len = adj.size();
    vector<bool> discovered(len, 0);
    deque<int> C;

    C.push_back(start);
    pushed.push_back(start);
    while(!C.empty()){
        int u = C.back();
        C.pop_back();
        if(discovered[u]){continue;}
        discovered[u] = 1;
        visited.push_back(u);
        for(int v : adj[u]){
            C.push_back(v);
            pushed.push_back(v);
        }
    }
}

void traverseQueue(const vector<vector<int>>& adj, int start, vector<int>& pushed, vector<int>& visited) {
    int len = adj.size();
    vector<bool> discovered(len, 0);
    deque<int> C;

    C.push_back(start);
    pushed.push_back(start);
    while(!C.empty()){
        int u = C.front();
        C.pop_front();
        if(discovered[u]){continue;}
        discovered[u] = 1;
        visited.push_back(u);
        for(int v : adj[u]){
            C.push_back(v);
            pushed.push_back(v);
        }
    }
}
