#pragma once
#include <vector>
struct GanttStep {
    int pid;        
    int startTime; 
    int endTime;    
};


extern std::vector<GanttStep> ganttLog;