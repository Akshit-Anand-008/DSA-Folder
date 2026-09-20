#pragma once
#include "common.h"

struct Task {
    int id;
    int priority;

    Task(int id, int priority) : id(id), priority(priority) {}

    // Ordering used by priority_queue<Task> to decide scheduling order.
    bool operator<(const Task& other) const;
};

// Pushes all tasks into a priority_queue<Task> and pops the first k,
// returning their ids in execution order.
vector<int> getExecutionOrder(vector<Task>& tasks, int k);
