#include <QCoreApplication>
#include <QDebug>
#include "MyThread.h"

void handleProgress(int value) {
    qDebug() << "Progress:" << value;
}

void handleProgress2(int value) {
    qDebug() << "Progress2:" << value;
}

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    qDebug() << "MyThread thread;";
    MyThread thread(nullptr,20);
    MyThread thread2(nullptr,5);

    qDebug() << "connect sender and signal of thread to local function handleProgress(int value)";
    QObject::connect(&thread, &MyThread::progress, handleProgress);
    QObject::connect(&thread2, &MyThread::progress, handleProgress2);

    thread.start();
    thread2.start();

    // Wait for all threads to continue with main program
    thread.wait();
    thread2.wait();

    qDebug() << "All thread actions should be complete!!!";

    return QCoreApplication::exec();
}
