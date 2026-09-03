#include "git-divergence.h"

Node* findDivergenceNaive(Node* headA, Node* headB) {
    Node* itA = headA;
    Node* itB = headB;
    while (itA != nullptr) {
        while (itB != nullptr) {
            if (itA == itB) { return itA; }
            itB = itB->next;
        }
        itB = headB;
        itA = itA->next;
    }
    return nullptr;
}

// i don't have this function working
// it is
Node* findDivergenceOptimized(Node* headA, Node* headB) {
    // cout << "hi" << endl;
    // I already have the the lenghts of the branches but I am not passing those here
    int lenA = 1, lenB = 1;
    Node* itA = headA;
    Node* itB = headB;
    while (itA != nullptr) {
        lenA++;
        itA = itA->next;
    }
    while (itB != nullptr) {
        lenB++;
        itB = itB->next;
    }
    // printf("lenA:%i, lenB:%i\n", lenA, lenB);
    // Now I need to find which is longer, and then move it forward by the difference of the 2 lenghts
    itA = headA;
    itB = headB;
    if (lenA > lenB) {
        int diff = lenA - lenB;
        while (diff--) { itA = itA->next; }
    }
    else {
        int diff = lenB - lenA;
        while (diff--) { itB = itB->next; }
    }

    while (itA != nullptr && itB != nullptr) {
        if (itA == itB) {
            // cout << "shit" << endl;
            return itA;
        }
        itA = itA->next;
        itB = itB->next;
    }

    return nullptr;
}
