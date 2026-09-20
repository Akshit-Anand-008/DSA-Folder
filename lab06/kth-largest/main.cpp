#include "common.h"
#include "kth-largest-element.h"

int main(int argc, char** argv) {
    if (argc > 1) {
        if (freopen(argv[1], "r", stdin) == nullptr) {
            std::cerr << "Error: Could not open input file " << argv[1] << std::endl;
            return 1;
        }
    }

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    vector<int> arr(N);

    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    int K;
    if (!(cin >> K)) return 0;

    int maxHeapAnswer = kthLargestMaxHeap(arr, K);
    int minHeapAnswer = kthLargestMinHeap(arr, K);

    cout << maxHeapAnswer << "\n";
    cout << minHeapAnswer << "\n";

    return 0;
}
