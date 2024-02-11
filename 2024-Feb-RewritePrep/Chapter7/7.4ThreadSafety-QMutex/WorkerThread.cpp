//
// Created by User on 2/11/2024.
//
#include "WorkerThread.h"
#include <QMutex>
#include <QDebug>
#include <string>

using namespace std;

extern QMutex qmutex; // Use extern to access the mutex declared in another file
extern int sharedResource; // Use extern to access the shared resource

void WorkerThread::run() {
    qDebug() << "Trying to lock mutex by" << QThread::currentThreadId() << " id: "<< this->id;
    qmutex.lock();

    qDebug() << "Mutex locked by" << QThread::currentThreadId() << " id: "<< this->id;

    // update teh shared resource, in this case just increment it;
    ++sharedResource;

    qDebug() << "---Shared Resource Value updated to " << sharedResource << "by" << QThread::currentThreadId()<< " id: "<< this->id << "---";
    qmutex.unlock();
    qDebug() << "Mutex unlocked by" << QThread::currentThreadId()<< " id: "<< this->id;
    qDebug() << "-------------------------------------------------------";
}
