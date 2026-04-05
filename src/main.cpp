#include <QApplication>
#include "gui.h"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    SchedulerGUI window;
    window.setWindowTitle("CPU Scheduling Simulator");
    window.resize(800,600);
    window.show();

    return app.exec();
}
