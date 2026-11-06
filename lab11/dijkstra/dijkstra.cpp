#include "dijkstra.h"

// --- Part 1: IndexedMinHeap ---

IndexedMinHeap::IndexedMinHeap(int n) {
/* --- Start of student code, Don't Remove or edit these markers --- */
// Code here


/* --- End of student code, Don't Remove or edit these markers --- */
}

bool IndexedMinHeap::empty() const {
    bool result = true;
/* --- Start of student code, Don't Remove or edit these markers --- */
// Code here
    result = this->heap.empty();

/* --- End of student code, Don't Remove or edit these markers --- */
    return result;
}

bool IndexedMinHeap::contains(int v) const {
    bool result = false;
/* --- Start of student code, Don't Remove or edit these markers --- */
// Code here
    for(auto i : this->heap){
        if(i.second == v){
            result = true;
        }
    }

/* --- End of student code, Don't Remove or edit these markers --- */
    return result;
}

void IndexedMinHeap::swapEntries(int i, int j) {
/* --- Start of student code, Don't Remove or edit these markers --- */
// Code here

/* --- End of student code, Don't Remove or edit these markers --- */
}

void IndexedMinHeap::siftUp(int i) {

/* --- Start of student code, Don't Remove or edit these markers --- */
// Code here

/* --- End of student code, Don't Remove or edit these markers --- */
}

void IndexedMinHeap::siftDown(int i) {
/* --- Start of student code, Don't Remove or edit these markers --- */
// Code here

/* --- End of student code, Don't Remove or edit these markers --- */
}

void IndexedMinHeap::insert(int v, Key key) {

/* --- Start of student code, Don't Remove or edit these markers --- */
// Code here
    vector<pair<Key, int>>& H = this->heap;
    H.push_back({key, v});
    // now bubble up
    int idx = H.size()-1;
    int ptr = (idx - 1)/2;
    while(H[ptr] > H[idx]){
        swap(H[ptr], H[idx]);
        idx = ptr;
        ptr = (idx - 1)/2;
    }

/* --- End of student code, Don't Remove or edit these markers --- */
}

void IndexedMinHeap::decreaseKey(int v, Key key) {
/* --- Start of student code, Don't Remove or edit these markers --- */
// Code here
    vector<pair<Key, int>>& H = this->heap;
    // Whenever you create new aliases be careful that you are not creating copies.
    for(auto i : H){
        if(i.second == v){
            if(i.first > key){
                i.first = key;
            }
            return;
        }
    }

/* --- End of student code, Don't Remove or edit these markers --- */
}

pair<int, Key> IndexedMinHeap::extractMin() {
    pair<int, Key> result;
/* --- Start of student code, Don't Remove or edit these markers --- */
// Code here
    vector<pair<Key, int>> H = this->heap;
    result.first = H[0].second;
    result.second = H[0].first;
    int len = H.size();
    swap(H[0], H[len-1]);
    H.pop_back();
    int idx = 0;
    int c1 = (idx + 1)/2;
    int c2 = (idx + 2)/2;

    while(idx < len && c1 < len && c2 < len){
        if(H[c1] >= H[idx] && H[c2] >= H[idx]){
            return result;
        }
        else if(H[c1] < H[idx] && H[c2] >= H[idx]){
            swap(H[c1], H[idx]);
            idx = c1;
        }
        else if(H[c2] < H[idx] && H[c1] >= H[idx]){
            swap(H[c2], H[idx]);
            idx = c2;
        }
        else if(H[c2] < H[idx] && H[c1] < H[idx]){
            int n = H[c1] < H[c2] ? c1 : c2;
            swap(H[n], H[idx]);
            idx = n;
        }
        c1 = (idx + 1)/2;
        c2 = (idx + 2)/2;
    }


/* --- End of student code, Don't Remove or edit these markers --- */
    return result;
}

// --- Part 2: Dijkstra ---

ShortestPaths dijkstra(const vector<vector<Edge>>& adj, int s) {
    ShortestPaths sp;

/* --- Start of student code, Don't Remove or edit these markers --- */
// Code here
    


/* --- End of student code, Don't Remove or edit these markers --- */
    return sp;
}

// --- Part 3: Path restoration ---

vector<int> restorePath(const ShortestPaths& sp, int s, int t) {
    vector<int> path;
/* --- Start of student code, Don't Remove or edit these markers --- */
// Code here

/* --- End of student code, Don't Remove or edit these markers --- */
    return path;
}

// --- Part 4: Meeting point ---

int meetingPoint(const vector<vector<Edge>>& adj, int a, int b) {
    int best = -1;
/* --- Start of student code, Don't Remove or edit these markers --- */
// Code here

/* --- End of student code, Don't Remove or edit these markers --- */
    return best;
}
