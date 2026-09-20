#include "task-scheduler.h"

// here this is a pointer but other is not
// other is another Task object passed with address
bool Task::operator<(const Task& other) const {
    if(this->priority == other.priority){
        return (this->id > other.id);
    }
    else{
        return this->priority < other.priority;
    }
}

vector<int> getExecutionOrder(vector<Task>& tasks, int k) {
    std::vector<int> A;
    std::priority_queue<Task> Q;
    for (auto t : tasks) { Q.push(t); }
    for (int i = 0; i < k; i++) { 
        A.push_back(Q.top().id);
        Q.pop();
    }
    const int i = 9;
    return A;
}
