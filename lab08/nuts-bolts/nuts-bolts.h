#pragma once
#include "common.h"

// Defined in main.cpp. Returns 0 if the nut fits the bolt, -1 if the bolt is
// too small for the nut, and 1 if the bolt is too large for the nut.
int tryFit(int nut, int bolt);

// nuts[lo..hi] and bolts[lo..hi] hold matching sets of nuts and bolts.
// Rearranges both ranges so that nuts[i] fits bolts[i] for every i in lo..hi.
void matchRange(vector<int>& nuts, vector<int>& bolts, int lo, int hi);

// Rearranges nuts and bolts so that nuts[i] fits bolts[i] for every i.
void matchNutsAndBolts(vector<int>& nuts, vector<int>& bolts);
