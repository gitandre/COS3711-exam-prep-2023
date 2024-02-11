// LoadBalancingThread.cpp
#include "LoadBalancingThread.h"
#include <QDebug>
#include <utility>

LoadBalancingThread::LoadBalancingThread(QMutex* mutex, int* taskCount, QString name): mutex(mutex), taskCount(taskCount), name(name) {}

void LoadBalancingThread::run() {

    while (true) {
        mutex->lock();

        if (*taskCount <= 0) {
            mutex->unlock();
            break;
        }

        (*taskCount)--;
        this->actioned++;
        qDebug() << "Executing task. Remaining:" << *taskCount << this->name;
        mutex->unlock();
    }
}