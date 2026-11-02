#pragma once
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

struct SealedCase {
    bool operator<(const SealedCase& other) const {
        ++comparisons;
        return (this->value < other.value);
    }

    static long long comparisons;

private:
    int value;

    explicit SealedCase(int v) : value(v) {}

    friend SealedCase make_sealed(int value);
    friend int reveal(const SealedCase& c);
};
