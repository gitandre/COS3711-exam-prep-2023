#include <QCoreApplication>
#include <QDebug>
#include <iostream>
#include <thread>

using namespace std;

void printNumbers(int val=5) {
    for (int i = 1; i <= val; ++i) {
        std::cout << "Number: " << i << std::endl;
    }
    cout << "print complete" << endl;

}

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    //create a new therad to print numbers off of the main thread
    thread t1(printNumbers, 15);
    // thread to join main thread i.e main thread waits for the thread to finish execution
    t1.join() ;

    cout << "main thread ending..." << endl;

    return QCoreApplication::exec();
}
