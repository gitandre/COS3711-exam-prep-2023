// MyTask.h
#ifndef MYTASK_H
#define MYTASK_H

#include <QRunnable>

class MyTask : public QRunnable {
public:
    MyTask(int value);
    void run() override;

private:
    int value;
};

#endif // MYTASK_H