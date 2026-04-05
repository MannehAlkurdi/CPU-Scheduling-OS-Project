#pragma once
#include "process.h"

// Scheduler algorithm placeholders
void FCFS();
void SJF(bool preemptive);
void PriorityScheduling(bool preemptive);
void RoundRobin(int quantum);

// Utility functions
void calculateMetrics();
