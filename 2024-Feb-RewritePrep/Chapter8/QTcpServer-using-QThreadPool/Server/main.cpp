// threadpool_server.cpp
#include <QCoreApplication>
#include <QTcpServer>
#include <QTcpSocket>
#include <QThreadPool>
#include <QRunnable>

class SocketTask : public QRunnable {
public:
    QTcpSocket* socket;

    void run() override {
        QObject::connect(socket, &QTcpSocket::readyRead, [this]() {
            QByteArray data = socket->readAll();
            qDebug() << "Received:" << data;
            socket->write("Hello, client");
            socket->deleteLater();
        });
    }
};

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    QTcpServer server;
    server.listen(QHostAddress::LocalHost, 8083);

    QObject::connect(&server, &QTcpServer::newConnection, [&]() {
        QTcpSocket *clientSocket = server.nextPendingConnection();
        
        SocketTask* task = new SocketTask;
        task->socket = clientSocket;

        QThreadPool::globalInstance()->start(task);
    });

    return a.exec();
}