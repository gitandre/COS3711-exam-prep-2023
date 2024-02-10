#include <QCoreApplication>
#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>

class SimpleServer : public QObject {
Q_OBJECT
public:
    SimpleServer() {
        connect(&server, &QTcpServer::newConnection, this, &SimpleServer::onNewConnection);
        if (!server.listen(QHostAddress::Any, 8080)) {
            qDebug() << "Server could not start!";
        } else {
            qDebug() << "Server started, listening on port 8080...";
        }
    }

private slots:
    void onNewConnection() {
        QTcpSocket *clientSocket = server.nextPendingConnection();

        connect(clientSocket, &QTcpSocket::readyRead, [this, clientSocket]() {
            qDebug() << "Client says:" << clientSocket->readAll();
            clientSocket->write("Hello from server");
            clientSocket->flush();
            clientSocket->disconnectFromHost();
        });
    }

private:
    QTcpServer server;
};

#include "main.moc"

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    SimpleServer server;

    return a.exec();
}

