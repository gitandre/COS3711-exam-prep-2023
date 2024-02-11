// CommunicateThread.h
#ifndef COMMUNICATETHREAD_H
#define COMMUNICATETHREAD_H

#include <QThread>
#include <QObject>

class CommunicatingThread : public QThread {
Q_OBJECT
public:
    void run() override;
    std::string m_name;

signals:
    void sendValue(int value,std::string name);

};

#endif // COMMUNICATETHREAD_H