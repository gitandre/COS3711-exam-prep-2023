#ifndef WORKERTHREAD_H
#define WORKERTHREAD_H

#include <QThread>

class WorkerThread : public QThread {
Q_OBJECT
public:
    void run() override;
    int id;
};

#endif // WORKERTHREAD_H
