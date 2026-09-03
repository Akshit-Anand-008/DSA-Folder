#pragma once
#include "common.h"

struct Process {
    string id;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int completion_time = 0;
    int turnaround_time = 0;
    int waiting_time = 0;
};

// Main scheduling function to be implemented by the student
void simulate_round_robin(Process processes[], int n, int time_quantum);
