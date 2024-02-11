// LoadBalancingThread.h
#ifndef LOADBALANCINGTHREAD_H
#define LOADBALANCINGTHREAD_H

#include <QThread>
#include <QMutex>
#include <QString>
class LoadBalancingThread : public QThread {
public:
    LoadBalancingThread(QMutex* mutex, int* taskCount, QString name);
    void run() override;
    int actioned = 0;

private:
    QMutex *mutex;
    int *taskCount;
    QString name;

};

#endif // LOADBALANCINGTHREAD_H