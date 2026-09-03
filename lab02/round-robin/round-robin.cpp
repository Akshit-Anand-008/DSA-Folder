#include "round-robin.h"

bool fun(Process p1, Process p2){
    if(p1.arrival_time == p2.arrival_time){
        return p1.id < p2.id;
    }
    else{
        return p1.arrival_time < p2.arrival_time;
    }
}

void simulate_round_robin(Process processes[], int n, int time_quantum) {
    std::sort(processes, processes+n, fun);

    int last_time = processes[0].arrival_time;
    int idx = 0;
    int processes_completed = 0;
    int curr = last_time;
    queue<Process*> Q;
    while(processes_completed<n){
        if(!Q.empty() && Q.front()->remaining_time == 0){
            Q.front()->completion_time = curr;
            Q.pop();
            last_time = curr;
            processes_completed++;
        }
        while(idx < n && processes[idx].arrival_time == curr){
            processes[idx].remaining_time = processes[idx].burst_time;
            Q.push(&(processes[idx]));
            idx++;
        }
        if(curr == last_time + time_quantum){
            if(!Q.empty()) {
                Process* p = Q.front();
                Q.pop();
                Q.push(p);
            }
            last_time = curr;
        }
        curr++;
        if(!Q.empty()){ Q.front()->remaining_time--; }
    }
    for (int i = 0; i < n; i++) {
        Process& p = processes[i];
        p.turnaround_time = p.completion_time - p.arrival_time;
        p.waiting_time = p.turnaround_time - p.burst_time;
    }
}
