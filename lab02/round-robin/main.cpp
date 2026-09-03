#include "common.h"
#include "round-robin.h"

int main(int argc, char** argv) {
    if (argc > 1) {
        if (freopen(argv[1], "r", stdin) == nullptr) {
            std::cerr << "Error: Could not open input file " << argv[1] << std::endl;
            return 1;
        }
    }

    int n, time_quantum;
    if (!(cin >> n >> time_quantum)) return 0;

    Process* processes = new Process[n];
    for (int i = 0; i < n; i++) {
        cin >> processes[i].id >> processes[i].arrival_time >> processes[i].burst_time;
        processes[i].remaining_time = processes[i].burst_time;
    }

    simulate_round_robin(processes, n, time_quantum);

    double total_tat = 0;
    double total_wt = 0;

    for (int i = 0; i < n; i++) {
        cout << "Process " << processes[i].id << ": "
             << "Arrival = " << processes[i].arrival_time << ", "
             << "Burst = " << processes[i].burst_time << ", "
             << "CT = " << processes[i].completion_time << ", "
             << "TAT = " << processes[i].turnaround_time << ", "
             << "WT = " << processes[i].waiting_time << "\n";
        total_tat += processes[i].turnaround_time;
        total_wt += processes[i].waiting_time;
    }

    printf("Average Turnaround Time = %.2f\n", total_tat / n);
    printf("Average Waiting Time = %.2f\n", total_wt / n);

    delete[] processes;
    return 0;
}
