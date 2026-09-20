#include <iostream>
#include <vector>
#include <queue>

int main(int argc, char **argv) {
    std::priority_queue<int> Q;
    Q.push(8);
    Q.push(9);
    Q.push(6);
    Q.push(90);
    while(!Q.empty()){
        std::cout << Q.top() << std::endl;
        Q.pop();
    }
    // this shit is in sorted order
}
