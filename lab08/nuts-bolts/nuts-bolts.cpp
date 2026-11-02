#include "nuts-bolts.h"

// --- Helper Functions (Already Implemented) ---

// Entry point: matches every nut with its bolt.
void matchNutsAndBolts(vector<int>& nuts, vector<int>& bolts) {
    matchRange(nuts, bolts, 0, (int)nuts.size() - 1);
}

// --- Student Implementation Section ---

int partition_bolts(vector<int> &bolts, int low, int high, int pivot_nut) {
    int i = low;
    int match_idx = high;
    for (int j = low; j < high; j++) {
        int r = tryFit(pivot_nut, bolts[j]);
        if (r == -1) { // bolts[j] < pivot_nut
            swap(bolts[i], bolts[j]);
            i++;
        } else if (r == 0) {
            match_idx = j;
        }
    }
    swap(bolts[match_idx], bolts[high]);
    
    // Now partition around the pivot value
    i = low;
    for (int j = low; j < high; j++) {
        int r = tryFit(pivot_nut, bolts[j]);
        if (r == -1) {
            swap(bolts[i], bolts[j]);
            i++;
        }
    }
    swap(bolts[i], bolts[high]);
    return i;
}

int partition_nuts(vector<int> &nuts, int low, int high, int pivot_bolt) {
    int i = low;
    int match_idx = high;
    for (int j = low; j < high; j++) {
        int r = tryFit(nuts[j], pivot_bolt);
        if (r == 1) { // nuts[j] < pivot_bolt (since tryFit(nut, bolt) returns 1 if bolt > nut, meaning nut < bolt)
            swap(nuts[i], nuts[j]);
            i++;
        } else if (r == 0) {
            match_idx = j;
        }
    }
    swap(nuts[match_idx], nuts[high]);
    
    i = low;
    for (int j = low; j < high; j++) {
        int r = tryFit(nuts[j], pivot_bolt);
        if (r == 1) {
            swap(nuts[i], nuts[j]);
            i++;
        }
    }
    swap(nuts[i], nuts[high]);
    return i;
}

void matchRange(vector<int>& nuts, vector<int>& bolts, int lo, int hi) {
    // Your code starts from here -- DO NOT EDIT ANYTHING ABOVE
    while (lo < hi) {
        // Pick a random nut as pivot to guarantee O(N log N) expected time
        int rand_idx = lo + rand() % (hi - lo + 1);
        swap(nuts[rand_idx], nuts[hi]);

        // Partition bolts using the chosen nut, returning the index of the matching bolt
        int pivot = partition_bolts(bolts, lo, hi, nuts[hi]);

        // Partition nuts using the matching bolt found
        partition_nuts(nuts, lo, hi, bolts[pivot]);

        // Tail-recursion optimization: recurse on the smaller half first
        if (pivot - lo < hi - pivot) {
            matchRange(nuts, bolts, lo, pivot - 1);
            lo = pivot + 1;
        } else {
            matchRange(nuts, bolts, pivot + 1, hi);
            hi = pivot - 1;
        }
    }
    // Your code ends here -- DO NOT EDIT ANYTHING BELOW
}
