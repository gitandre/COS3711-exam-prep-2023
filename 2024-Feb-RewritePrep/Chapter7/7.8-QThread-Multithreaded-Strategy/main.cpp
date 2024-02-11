// main.cpp
#include <QCoreApplication>
#include <QMutex>
#include "LoadBalancingThread.h"

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    //Create a mutex and an integer to be a proxy for a task
    QMutex mutex;
    int taskCount = 1000;

    // Create 3 loadbalancers and pass the same mutex and taskcount to each as a pointer
    LoadBalancingThread thread1(&mutex, &taskCount,QString("LoadBalancingThread1"));
    LoadBalancingThread thread2(&mutex, &taskCount,QString("LoadBalancingThread2"));
    LoadBalancingThread thread3(&mutex, &taskCount,QString("LoadBalancingThread3"));

    // Start
    thread1.start();
    thread2.start();
    thread3.start();

    // Wait for all to finish
    thread1.wait();
    thread2.wait();
    thread3.wait();

    // Print the totals that each LoadBalancingThread processed
    qDebug() << "\nTotals:------------------------------";
    qDebug() << "thread1 total: " << thread1.actioned;
    qDebug() << "thread2 total: " << thread2.actioned;
    qDebug() << "thread3 total: " << thread3.actioned;

    return a.exec();
}