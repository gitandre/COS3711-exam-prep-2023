#include <QCoreApplication>
#include <QTcpServer>
#include <QTcpSocket>
#include <QThread>
#include <QDebug>
#include <QAbstractSocket>

class Worker : public QObject {
    Q_OBJECT
public slots:
    void doWork(QTcpSocket* clientSocket) {
        // Ensure we capture 'this' in the lambda to avoid issues with object lifetimes
        connect(clientSocket, &QTcpSocket::readyRead, this, [this, clientSocket]() {
            QByteArray data = clientSocket->readAll();
            qDebug() << "Received from client:" << data;
            QByteArray response = "Hello, client. Your message was received. client_message: '" + data + "'";
            clientSocket->write(response);
            clientSocket->flush(); // Make sure the data is sent immediately
//            clientSocket->disconnectFromHost(); // Optional: Close connection after responding
        });
    }
};

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    QTcpServer server;
    // Listen on all interfaces at port x
    int port = 8083;
    if (!server.listen(QHostAddress::LocalHost, port)) {
        qDebug() << "Server could not start!";
        return -1;
    }
    qDebug() << "Server started OK on " << port;

    QObject::connect(&server, &QTcpServer::newConnection, [&server]() {
        QTcpSocket* clientSocket = server.nextPendingConnection();
        QThread* thread = new QThread;
        Worker* worker = new Worker;

        worker->moveToThread(thread);
        QObject::connect(thread, &QThread::finished, worker, &QObject::deleteLater);
        QObject::connect(thread, &QThread::started, [worker, clientSocket]() { worker->doWork(clientSocket); });
        QObject::connect(clientSocket, &QTcpSocket::disconnected, thread, &QThread::quit);
        QObject::connect(clientSocket, &QTcpSocket::disconnected, clientSocket, &QTcpSocket::deleteLater);
        thread->start();

    });

    qDebug() << "Server started. Listening for connections...";
    return a.exec();
}

#include "main.moc" // Include this if you're not using a .pro file to run moc automatically
