#include "scheduler.h"
#include <iostream>

std::vector<Process> processes;
SchedulerType currentScheduler;
int timeQuantum = 2;

// Scheduler placeholders
void FCFS() { /* TODO */ }
void SJF(bool preemptive) { /* TODO */ }
void PriorityScheduling(bool preemptive) { /* TODO */ }
void RoundRobin(int quantum) { /* TODO */ }

void calculateMetrics() { std::cout << "Calculating metrics...\n"; }
