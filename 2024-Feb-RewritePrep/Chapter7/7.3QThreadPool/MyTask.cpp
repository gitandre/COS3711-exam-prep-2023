// MyTask.cpp
#include "MyTask.h"
#include <QDebug>
#include <QTime>

MyTask::MyTask(int value) : value(value) {}

void MyTask::run() {

    qDebug() << "---Starting task with value:" << value;

    // fake some 'random' work
    QTime delay = QTime::currentTime().addMSecs(value * 1000);
    qDebug() << "Will delay by (ms)" << value;
    while (QTime::currentTime() < delay) {
        // do nothing but wait
//        qDebug() << value << " is waiting...";
    }
    qDebug() << "------Completing task with value:" << value;
    // Perform the task
}