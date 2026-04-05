import os

# Base project path
project_path = r"C:\Users\maria\Downloads\OS Project"

# Folders to create
folders = ["include", "src"]
for f in folders:
    os.makedirs(os.path.join(project_path, f), exist_ok=True)

# Files and their content
files = {
    "include/process.h": """#pragma once
#include <vector>

struct Process {
    int pid;
    int arrivalTime;
    int burstTime;
    int remainingTime;
    int priority; // only for priority scheduler
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
""",

    "include/scheduler.h": """#pragma once
#include "process.h"

// Scheduler algorithm placeholders
void FCFS();
void SJF(bool preemptive);
void PriorityScheduling(bool preemptive);
void RoundRobin(int quantum);

// Utility functions
void calculateMetrics();
""",

    "include/gui.h": """#pragma once
#include <QWidget>
#include <QTimer>
#include <QTableWidget>
#include <QLabel>
#include <QGraphicsView>
#include <QGraphicsScene>

class SchedulerGUI : public QWidget {
    Q_OBJECT
public:
    SchedulerGUI(QWidget* parent = nullptr);

private slots:
    void startScheduler();
    void updateSimulation();
    void addProcess();

private:
    QTableWidget* table;
    QLabel* avgWaitingTimeLabel;
    QLabel* avgTurnaroundTimeLabel;
    QGraphicsView* ganttView;
    QGraphicsScene* scene;
    QTimer* timer;
};
""",

    "src/scheduler.cpp": """#include "scheduler.h"
#include <iostream>

std::vector<Process> processes;
SchedulerType currentScheduler;
int timeQuantum = 2;

// Scheduler placeholders
void FCFS() { /* TODO */ }
void SJF(bool preemptive) { /* TODO */ }
void PriorityScheduling(bool preemptive) { /* TODO */ }
void RoundRobin(int quantum) { /* TODO */ }

void calculateMetrics() { std::cout << "Calculating metrics...\\n"; }
""",

    "src/gui.cpp": """#include "gui.h"
#include "scheduler.h"
#include <QVBoxLayout>
#include <QPushButton>

SchedulerGUI::SchedulerGUI(QWidget* parent) : QWidget(parent) {
    QVBoxLayout* layout = new QVBoxLayout(this);

    avgWaitingTimeLabel = new QLabel("Average Waiting Time: 0", this);
    avgTurnaroundTimeLabel = new QLabel("Average Turnaround Time: 0", this);

    table = new QTableWidget(this);
    table->setColumnCount(3);
    table->setHorizontalHeaderLabels({"PID","Remaining Time","Priority"});

    scene = new QGraphicsScene(this);
    ganttView = new QGraphicsView(scene,this);
    ganttView->setMinimumHeight(200);

    QPushButton* addProcessBtn = new QPushButton("Add Process",this);
    QPushButton* startBtn = new QPushButton("Start Scheduler",this);

    layout->addWidget(avgWaitingTimeLabel);
    layout->addWidget(avgTurnaroundTimeLabel);
    layout->addWidget(table);
    layout->addWidget(ganttView);
    layout->addWidget(addProcessBtn);
    layout->addWidget(startBtn);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &SchedulerGUI::updateSimulation);
    connect(startBtn, &QPushButton::clicked, this, &SchedulerGUI::startScheduler);
    connect(addProcessBtn, &QPushButton::clicked, this, &SchedulerGUI::addProcess);
}

void SchedulerGUI::startScheduler() { timer->start(1000); }
void SchedulerGUI::updateSimulation() { /* TODO */ }
void SchedulerGUI::addProcess() { /* TODO */ }
""",

    "src/main.cpp": """#include <QApplication>
#include "gui.h"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    SchedulerGUI window;
    window.setWindowTitle("CPU Scheduling Simulator");
    window.resize(800,600);
    window.show();

    return app.exec();
}
""",

    "CMakeLists.txt": """cmake_minimum_required(VERSION 3.5)
project(CPUSchedulerProject LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(CPUSchedulerProject src/main.cpp src/gui.cpp src/scheduler.cpp)
target_include_directories(CPUSchedulerProject PRIVATE include)
target_link_libraries(CPUSchedulerProject PRIVATE Qt6::Widgets)
""",

    "README.md": """# CPU Scheduling Simulator
C++ Qt-based CPU Scheduling Simulator.
Features:
- FCFS, SJF (Preemptive & Non-preemptive), Priority (Preemptive & Non-preemptive), Round Robin
- Live simulation with 1 unit = 1 second
- Dynamic process addition
- Gantt chart visualization
- Remaining burst time table
- Average waiting & turnaround time
"""
}

# Write files
for path, content in files.items():
    full_path = os.path.join(project_path, path.replace("/", os.sep))
    with open(full_path, "w", encoding="utf-8") as f:
        f.write(content)

print("Project skeleton created successfully!")