#include <QCoreApplication>
#include <QDebug>
#include "WorkerThread.h"
#include <QMutex>
#include <QDebug>

QMutex qmutex;
int sharedResource = 0;

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    // Spin up Worker threads and set a simple id for tracking who locked and updated when
    WorkerThread thread1;
    thread1.id = 1;

    WorkerThread thread2;
    thread2.id = 2;

    WorkerThread thread3;
    thread3.id = 3;

    // Start the threads...
    thread1.start();
    thread2.start();
    thread3.start();

    // Wait for all threads to be done
    thread1.wait();
    thread2.wait();
    thread3.wait();

    qDebug() << "--I run at the end of all the threads being done--" ;
    return QCoreApplication::exec();
}
