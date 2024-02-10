#include <QCoreApplication>
#include <QUdpSocket>
#include <QDebug>

class UdpServer : public QObject {
Q_OBJECT
public:
    UdpServer() {
        udpSocket = new QUdpSocket(this);

        if (!udpSocket->bind(QHostAddress::LocalHost, 49153)) {
            qDebug() << "Error: " << udpSocket->errorString();
            return;
        }
        qDebug() << "Server listening on port 49153";

        connect(udpSocket, &QUdpSocket::readyRead, this, &UdpServer::readDatagrams);
    }

private slots:
    void readDatagrams() {
        while (udpSocket->hasPendingDatagrams()) {
            QByteArray datagram;
            datagram.resize(udpSocket->pendingDatagramSize());
            udpSocket->readDatagram(datagram.data(), datagram.size());
            qDebug() << "Received datagram:" << datagram;
        }
    }

private:
    QUdpSocket *udpSocket;
};

#include "main.moc"

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    UdpServer server;

    return a.exec();
}
