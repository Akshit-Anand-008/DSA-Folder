#pragma once
#include "common.h"

// A heap key is (distance, hops). Keys are compared lexicographically, which
// is exactly how std::pair's operator< already behaves.
using Key = pair<long long, int>;
// key is {distance, hops}

struct Edge {
    int to;
    long long w; // 0 <= w <= 10^9
};

// Min-heap over the vertices 0..n-1, where every vertex is in the heap at most
// once and can be located in O(1) through a position directory.
//
// The heap stores entries (key, v) and orders them with operator< on
// pair<Key, int>, i.e. by distance, then hops, then vertex number. Because
// of the last component there are never two equal entries, so extractMin() is
// completely deterministic.
class IndexedMinHeap {
public:
    // Empty heap that can hold vertices 0..n-1.
    explicit IndexedMinHeap(int n);

    // True iff the heap has no vertices.
    bool empty() const;

    // True iff v is currently in the heap.
    bool contains(int v) const;

    // Insert v with the given key. Precondition: v is not in the heap.
    void insert(int v, Key key);

    // If v is in the heap and key is strictly smaller than its current key,
    // lower its key to `key`. Otherwise do nothing. Precondition: v is in the heap.
    void decreaseKey(int v, Key key);

    // Remove and return the vertex with the smallest entry together with its key.
    // Precondition: the heap is not empty.
    pair<int, Key> extractMin();

private:
    vector<pair<Key, int>> heap; // the binary heap, stored in an array
    vector<int> pos;             // pos[v] = index of v in heap, or -1 if v is not in the heap

    void siftUp(int i);
    void siftDown(int i);
    void swapEntries(int i, int j); // swaps heap[i], heap[j] and keeps pos[] consistent
};

struct ShortestPaths {
    // For every vertex v:
    //   dist[v]   = length of a shortest s-v path, or -1 if v is unreachable
    //   hops[v]   = fewest edges among all shortest (by length) s-v paths, or -1 if unreachable
    //   parent[v] = predecessor of v on the chosen shortest path, or -1 if unreachable.
    //               parent[s] = s.
    // The chosen path for v is: among all paths with minimum (dist, hops),
    // the one that, walking back from v, always picks the smallest-numbered predecessor.
    // Concretely, parent[v] is the smallest u with an edge (u,v,w) such that
    //   dist[u] + w == dist[v]  and  hops[u] + 1 == hops[v].
    vector<long long> dist;
    vector<int> hops;
    vector<int> parent;
};

// Dijkstra's algorithm from s on the undirected weighted graph adj, using
// IndexedMinHeap with key (distance, hops). Vertices are inserted into the heap
// when they are first discovered (not all up front with key infinity).
ShortestPaths dijkstra(const vector<vector<Edge>>& adj, int s);

// The path s, ..., t following parent[], or an empty vector if t is unreachable.
vector<int> restorePath(const ShortestPaths& sp, int s, int t);

// Among the vertices reachable from both a and b, return the one minimising
// max(d(a,v), d(b,v)); break ties by the smaller vertex number.
// Return -1 if no vertex is reachable from both.
int meetingPoint(const vector<vector<Edge>>& adj, int a, int b);
