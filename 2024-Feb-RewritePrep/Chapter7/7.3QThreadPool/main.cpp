#include <QCoreApplication>
#include <QThreadPool>
#include "MyTask.h"

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    QThreadPool pool;

    int workers = 5;
    qDebug() << "Creating " << workers << " workers...";
    for (int i = 0; i <= workers; ++i) {
        MyTask *task = new MyTask(i);
        pool.start(task);
    }

    // Wait for the pool of threads or tasks to be completed
    qDebug() << "\nWaiting for pool... pool.waitForDone()";
    pool.waitForDone();


    qDebug() << "\nI run after the pool is complete :)";

    return QCoreApplication::exec();
}
