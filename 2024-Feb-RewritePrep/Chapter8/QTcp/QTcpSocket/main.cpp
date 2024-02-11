#include <QCoreApplication>
#include <QDebug>
#include <QTcpSocket>
#include <QDebug>

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    QTcpSocket socket;
    socket.connectToHost("localhost", 8080);

    if (socket.waitForConnected()) {
        socket.write("Hello, server");
        socket.waitForBytesWritten();
        socket.waitForReadyRead();
        qDebug() << "Server response:" << socket.readAll();
        socket.close();
    } else {
        qDebug() << "Connection failed:" << socket.errorString();
    }

    return QCoreApplication::exec();
}
