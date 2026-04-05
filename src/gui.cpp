#include "gui.h"
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
