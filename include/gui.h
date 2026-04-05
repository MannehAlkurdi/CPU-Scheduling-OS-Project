#pragma once
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
