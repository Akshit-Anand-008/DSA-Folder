#include "list-inversion.h"

Node* reverse_list(Node* head) {
    if (head->next == nullptr) { return head; }
    if (head->next->next == nullptr) {
        head->next->next = head;
        Node* tmp = head->next;
        head->next = nullptr;
        return tmp;
    }
    Node* ptr = head->next;
    Node* pptr = head;
    head->next = nullptr;
    while (ptr != nullptr) {
        Node* tmp = ptr->next;
        ptr->next = pptr;
        pptr = ptr;
        ptr = tmp;
    }
    return pptr;
}
