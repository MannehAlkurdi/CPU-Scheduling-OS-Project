#pragma once
#include <vector>
struct Process {
    int pid;
    int arrivalTime;
    int burstTime;
    int remainingTime;
    int priority; 
    int completionTime = 0;
    int waitingTime = 0;
    int turnaroundTime = 0;
};
enum SchedulerType {
    FCFS,
    SJF_PREEMPTIVE,
    SJF_NON_PREEMPTIVE,
    PRIORITY_PREEMPTIVE,
    PRIORITY_NON_PREEMPTIVE,
    ROUND_ROBIN
};

extern std::vector<Process> processes;
extern SchedulerType currentScheduler;
extern int timeQuantum;
