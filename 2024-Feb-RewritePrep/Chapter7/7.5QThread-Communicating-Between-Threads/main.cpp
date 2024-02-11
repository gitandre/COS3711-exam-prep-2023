// main.cpp
#include <QCoreApplication>
#include "CommunicatingThread.h"
#include <QDebug>

// This is the slot function
void receiveValue(int value, std::string name) {
    qDebug() << "Received value:" << value << "from " << name;
}

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    //Create communicating threads
    CommunicatingThread thread1;
    thread1.m_name = "thread1";
    CommunicatingThread thread2;
    thread2.m_name = "thread2";
    CommunicatingThread thread3;
    thread3.m_name = "thread3";

    // Connect the signal to the local function(slow)
    QObject::connect(&thread1, &CommunicatingThread::sendValue, receiveValue);
    QObject::connect(&thread2, &CommunicatingThread::sendValue, receiveValue);
    QObject::connect(&thread3, &CommunicatingThread::sendValue, receiveValue);

    // start the threads
    thread1.start();
    thread2.start();
    thread3.start();

    // wait for the threads to complete
    thread1.wait();
    thread2.wait();
    thread3.wait();

    qDebug() << "--I run after the threads are complete!!!---";

    return a.exec();
}