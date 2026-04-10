#pragma once
#include <QWidget>
#include <QTimer>
#include <QTableWidget>
#include <QLabel>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QLineEdit>    
#include <QComboBox>    
#include <queue>   // 🔥 Round Robin

class SchedulerGUI : public QWidget {
    Q_OBJECT
public:
    explicit SchedulerGUI(QWidget* parent = nullptr);

private slots:
    void startScheduler();
    void updateSimulation();
    void addProcess();

private:
    
    // 🔹 Inputs
    QLineEdit* arrivalInput;
    QLineEdit* burstInput;
    QLineEdit* priorityInput;

    QComboBox* algoSelect;
    QComboBox* modeSelect;   // 🔥 Live / Offline


    // 🔹 Outputs
    QLabel* avgWaitingTimeLabel;
    QLabel* avgTurnaroundTimeLabel;

    QTableWidget* table;
    QGraphicsView* ganttView;
    QGraphicsScene* scene;

    
    // 🔹 Timer
    QTimer* timer;
    int currentStepIndex; 


    // 🔥 Live Simulation Variables 
    int currentTime;
    int lastExecutedPid;
    int stepStartTime;
    bool isRunning;

    // 🔥 Non-Preemptive fix (SJF + Priority)
    int currentProcessIndex = -1;

    // 🔥 Round Robin
    std::queue<int> readyQueue;
    int quantum = 2;


    // 🔥 Core function
    void simulateStep();
};
