#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
using vint = vector<int>;

template <typename T>
void vprint(T& V) {
    for (auto& i : V) { cout << i << " "; }
    cout << "\n";
}

template <typename T>
void pprint(T& P) {
    for (auto& i : P) { cout << i.first << " " << i.second << "\n"; }
    cout << "\n";
}

struct node{
    int val;
    node* left = nullptr;
    node* right = nullptr;
};

// Elemets are always added to the bottom right
class Heap{
    node* root = nullptr; //an empty Heap
    node* last = nullptr; // pointer to the last element which has been filled
    bool left_empty = true; 
    public:
    Heap(); // initialises an empty Heap with root=nullptr
    Heap(int val){
        node* root = new node{val};
        last = root;
        // initialises a heap with one element
    }

};

int main(int argc, char **argv) {

}
