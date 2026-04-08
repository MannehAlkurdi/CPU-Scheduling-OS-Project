#include "scheduler.h"
#include "GanttStep.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>


std::vector<Process> processes;
std::vector<GanttStep> ganttLog; 

void updateFinalMetrics() {
    for (auto& p : processes) {
        p.turnaroundTime = p.completionTime - p.arrivalTime;
        p.waitingTime = p.turnaroundTime - p.burstTime;
    }
}

void FCFS() {
    ganttLog.clear();
    std::sort(processes.begin(), processes.end(), [](const Process& a, const Process& b) {
        return a.arrivalTime < b.arrivalTime;
    });

    int currentTime = 0;
    for (auto& p : processes) {
        if (currentTime < p.arrivalTime) currentTime = p.arrivalTime;
        
        int start = currentTime;
        p.completionTime = currentTime + p.burstTime;
        currentTime = p.completionTime;
        
        ganttLog.push_back({p.pid, start, currentTime});
    }
    updateFinalMetrics();
}

void SJF(bool preemptive) {
    ganttLog.clear();
    int n = processes.size();
    int currentTime = 0, completed = 0;
    int lastPid = -1, startTime = 0;
    std::vector<bool> isDone(n, false);

    for(auto &p : processes) p.remainingTime = p.burstTime;

    while (completed < n) {
        int idx = -1;
        int minVal = 1e9;

        for (int i = 0; i < n; i++) {
            if (processes[i].arrivalTime <= currentTime && !isDone[i]) {
                int val = preemptive ? processes[i].remainingTime : processes[i].burstTime;
                if (val < minVal) { minVal = val; idx = i; }
            }
        }

        if (idx != -1) {
            if (preemptive) {
                if (processes[idx].pid != lastPid) {
                    if (lastPid != -1) ganttLog.push_back({lastPid, startTime, currentTime});
                    lastPid = processes[idx].pid; startTime = currentTime;
                }
                processes[idx].remainingTime--;
                currentTime++;
                if (processes[idx].remainingTime == 0) {
                    processes[idx].completionTime = currentTime;
                    isDone[idx] = true; completed++;
                }
            } else {
                int start = currentTime;
                currentTime += processes[idx].burstTime;
                processes[idx].completionTime = currentTime;
                ganttLog.push_back({processes[idx].pid, start, currentTime});
                isDone[idx] = true; completed++;
            }
        } else { currentTime++; }
    }
    if (preemptive && lastPid != -1) ganttLog.push_back({lastPid, startTime, currentTime});
    updateFinalMetrics();
}


void PriorityScheduling(bool preemptive) {
    ganttLog.clear();
    int n = processes.size();
    int currentTime = 0, completed = 0;
    int lastPid = -1, startTime = 0;
    std::vector<bool> isDone(n, false);

    for(auto &p : processes) p.remainingTime = p.burstTime;

    while (completed < n) {
        int idx = -1, bestPrio = 1e9;
        for (int i = 0; i < n; i++) {
            if (processes[i].arrivalTime <= currentTime && !isDone[i]) {
                if (processes[i].priority < bestPrio) { bestPrio = processes[i].priority; idx = i; }
            }
        }

        if (idx != -1) {
            if (preemptive) {
                if (processes[idx].pid != lastPid) {
                    if (lastPid != -1) ganttLog.push_back({lastPid, startTime, currentTime});
                    lastPid = processes[idx].pid; startTime = currentTime;
                }
                processes[idx].remainingTime--;
                currentTime++;
                if (processes[idx].remainingTime == 0) {
                    processes[idx].completionTime = currentTime;
                    isDone[idx] = true; completed++;
                }
            } else {
                int start = currentTime;
                currentTime += processes[idx].burstTime;
                processes[idx].completionTime = currentTime;
                ganttLog.push_back({processes[idx].pid, start, currentTime});
                isDone[idx] = true; completed++;
            }
        } else { currentTime++; }
    }
    if (preemptive && lastPid != -1) ganttLog.push_back({lastPid, startTime, currentTime});
    updateFinalMetrics();
}

// 4. Round Robin
void RoundRobin(int quantum) {
    ganttLog.clear();
    std::sort(processes.begin(), processes.end(), [](const Process& a, const Process& b) {
        return a.arrivalTime < b.arrivalTime;
    });

    std::queue<int> readyQ;
    int n = processes.size();
    int currentTime = 0, completed = 0, idx = 0;
    std::vector<bool> inQueue(n, false);
    for(auto &p : processes) p.remainingTime = p.burstTime;

    while (completed < n) {
        while (idx < n && processes[idx].arrivalTime <= currentTime) {
            if (!inQueue[idx]) { readyQ.push(idx); inQueue[idx] = true; }
            idx++;
        }

        if (!readyQ.empty()) {
            int i = readyQ.front(); readyQ.pop();
            int start = currentTime;
            int exec = std::min(processes[i].remainingTime, quantum);
            processes[i].remainingTime -= exec;
            currentTime += exec;
            ganttLog.push_back({processes[i].pid, start, currentTime});

            while (idx < n && processes[idx].arrivalTime <= currentTime) {
                if (!inQueue[idx]) { readyQ.push(idx); inQueue[idx] = true; }
                idx++;
            }
            if (processes[i].remainingTime > 0) readyQ.push(i);
            else {
                processes[i].completionTime = currentTime;
                completed++;
            }
        } else { currentTime++; }
    }
    updateFinalMetrics();
}

void calculateMetrics() {

    std::cout << "Metrics updated in process vector." << std::endl;
}