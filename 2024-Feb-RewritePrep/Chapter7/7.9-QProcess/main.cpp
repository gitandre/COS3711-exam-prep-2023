// main.cpp
#include <QCoreApplication>
#include <QProcess>
#include <QDebug>
#include <QTextStream>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    QProcess process;

    // start the cmd program and pass the following args
    process.start("cmd.exe", QStringList() << "/C" << "dir");

    if (process.waitForFinished()) {
        qDebug() << "Process finished. Output:";

        // Create a text stream to read from the process's standard output
        QTextStream stream(&process);
        while (!stream.atEnd()) {
            QString line = stream.readLine();

            //output line by line
            cout << line.toStdString() << endl;
        }
    } else {
        qDebug() << "Process failed:" << process.errorString();
    }
    return a.exec();
}