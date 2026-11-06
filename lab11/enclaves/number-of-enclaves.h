#pragma once
#include "common.h"

// Returns the number of land cells (1) from which it is not possible to walk
// off the boundary of the grid. A move goes to a 4-directionally adjacent
// land cell, or off the grid from a land cell on the boundary.
int numEnclaves(const vector<vector<int>>& grid);
