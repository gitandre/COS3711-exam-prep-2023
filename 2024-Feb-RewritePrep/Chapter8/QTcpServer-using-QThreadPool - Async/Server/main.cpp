#include <QCoreApplication>
#include <QTcpServer>
#include <QTcpSocket>
#include <QThread>
#include <QDebug>

// Define a Worker class that handles socket communication
class SocketWorker : public QObject {
Q_OBJECT
public:
    explicit SocketWorker(QTcpSocket* socket, QObject *parent = nullptr) : QObject(parent), socket(socket) {
        // Move the socket to the worker thread
        socket->setParent(this);
        connect(socket, &QTcpSocket::readyRead, this, &SocketWorker::onReadyRead);
        connect(socket, &QTcpSocket::disconnected, this, &SocketWorker::onDisconnected);
    }

public slots:
    void onReadyRead() {
        QByteArray data = socket->readAll();
        qDebug() << "Received:" << data;
        socket->write("Hello, client from Async SocketWorker");
    }

    void onDisconnected() {
        socket->deleteLater();
        thread()->quit();
    }

private:
    QTcpSocket* socket;
};

// Main server application
int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    QTcpServer server;
    if (!server.listen(QHostAddress::LocalHost, 8083)) {
        qDebug() << "Server could not start!";
        return -1;
    }

    QObject::connect(&server, &QTcpServer::newConnection, [&]() {
        QTcpSocket *clientSocket = server.nextPendingConnection();
        QThread *thread = new QThread;

        SocketWorker *worker = new SocketWorker(clientSocket);
        worker->moveToThread(thread);

        QObject::connect(thread, &QThread::started, worker, [worker]() {
            qDebug() << "Worker thread started.";
        });

        QObject::connect(thread, &QThread::finished, thread, &QThread::deleteLater);
        QObject::connect(worker, &SocketWorker::destroyed, thread, [thread]() {
            thread->quit();
        });

        thread->start();
    });

    qDebug() << "Server started. Listening for connections...";
    return a.exec();
}

#include "main.moc"
