#pragma once
#include <QWidget>
#include <QTimer>
#include <QTableWidget>
#include <QLabel>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QLineEdit>    
#include <QComboBox>    

class SchedulerGUI : public QWidget {
    Q_OBJECT
public:
    explicit SchedulerGUI(QWidget* parent = nullptr);

private slots:
    void startScheduler();
    void updateSimulation();
    void addProcess();

private:
    
    QLineEdit* arrivalInput;
    QLineEdit* burstInput;
    QLineEdit* priorityInput;
    QComboBox* algoSelect;


    QLabel* avgWaitingTimeLabel;
    QLabel* avgTurnaroundTimeLabel;


    QTableWidget* table;
    QGraphicsView* ganttView;
    QGraphicsScene* scene;

    
    QTimer* timer;
    int currentTime;
    int lastExecutedPid;
    int stepStartTime;
    bool isRunning;

    void simulateStep();
};
