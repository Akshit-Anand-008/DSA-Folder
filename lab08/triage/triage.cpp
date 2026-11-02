#include "triage.h"

pair<SealedCase, SealedCase> find_first_and_last(vector<SealedCase>& cases) {
    // And i need to use name cases directly as I can't assign it another name
    // I can return directly as {} and I should do that
    // I don't have any matching constructor to initialise this way
    int len = cases.size();
    if (len == 1) { return {cases[0], cases[0]}; }

    SealedCase gmin = cases[0];
    SealedCase gmax = cases[0];
    int stidx = 1;
    int even = (len % 2 == 0);
    if (even) {
        gmax = cases[1];
        bool straight = cases[0] < cases[1];
        if (!straight) {
            gmin = cases[1];
            gmax = cases[0];
        }
        stidx = 2;
    }

    // std::cout << reveal(gmin) << " " << reveal(gmax) << std::endl;
    for (int i = stidx; i <= len - 2; i += 2) {
        SealedCase less = cases[i];
        SealedCase more = cases[i + 1];
        bool needtoreverse = cases[i + 1] < cases[i];
        if (needtoreverse) {
            more = cases[i];
            less = cases[i + 1];
        }
        // gmin = less < gmin ? less : gmin;
        if (less < gmin) { gmin = less; }
        gmax = more < gmax ? gmax : more;
        // std::cout << "i: " << i << std::endl;
        // std::cout << reveal(gmin) << " " << reveal(gmax) << std::endl;
    }
    // For every 2 elements we are taking 3 comparisons
    return {gmin, gmax};
}

pair<SealedCase, SealedCase> find_smallest_and_second_smallest(vector<SealedCase>& cases) {
    struct defeated {
        SealedCase winner;
        vector<SealedCase> list;
    };

    vector<defeated> array;
    // for (auto : cases) { std::cout << 2 << std::endl; }
    // why the fuck can't I loop thorugh this

    while (true) {
        int len = array.size();
        bool odd = (len % 2 == 1);
        vector<SealedCase> newarray;
        if (odd) {
            newarray.push_back(array[array.size() - 1]);
            array.pop_back();
        }
        len = (len / 2) * 2;

        for (int i = 0; i <= len - 2; i += 2) {
            SealedCase first = cases[i];
            SealedCase second = cases[i + 1];
            bool order = first < second;
            if (order) {
                // defeated{firt, second}
            }
        }
    }

    return {cases[0], cases[0]};
}
