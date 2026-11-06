#pragma once
#include "common.h"

// adj[u] lists the neighbors of u, in the order the edges were given.
//
// Runs the generic traversal template from lecture, with a stack as the
// container: push start. While the container is not empty, extract a node.
// If it is already visited, discard it and continue. Otherwise mark it
// visited, append it to visited, and push every neighbor in adj order
// (whether or not it is already visited). Appends every node to pushed at
// the moment it is pushed, so a node can appear in pushed more than once but
// appears in visited exactly once.
void traverseStack(const vector<vector<int>>& adj, int start, vector<int>& pushed, vector<int>& visited);

// Same template, with a queue as the container instead of a stack.
void traverseQueue(const vector<vector<int>>& adj, int start, vector<int>& pushed, vector<int>& visited);
