// main.cpp
#include <QCoreApplication>
#include <QProcess>
#include <QDebug>
#include <QTextStream>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    // start the cmd program and pass the following args
    QProcess process1;
    process1.start("cmd.exe", QStringList() << "/C" << "dir");

    if (process1.waitForFinished()) {

        cout << "Process1 finished \nOutput:\n" << endl;
        cout << "-----------------------------" << endl;
        // Create a text stream to read from the process's standard output
        QTextStream stream(&process1);
        while (!stream.atEnd()) {
            QString line = stream.readLine();

            //output line by line
            cout << line.toStdString() << endl;
        }
    } else {
        qDebug() << "Process1 failed:" << process1.errorString();
    }

    QProcess process2;

    // Start notepad for no reason at all :)
    process2.start("notepad.exe");
    if (process2.waitForFinished()) {
        qDebug() << "Process2 finished";
    } else {
        qDebug() << "Process2 failed:" << process2.errorString();
    }


    return a.exec();
}