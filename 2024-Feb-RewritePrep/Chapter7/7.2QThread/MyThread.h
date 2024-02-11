// MyThread.h
#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>

class MyThread : public QThread {
Q_OBJECT
public:
    MyThread(QObject *parent, int val) : m_val(val),QThread(parent) {}
    void run() override;

signals:
    void progress(int);
private:
    int m_val;
};

#endif // MYTHREAD_H