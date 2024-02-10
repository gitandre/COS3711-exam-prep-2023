#include <QCoreApplication>
#include <QDebug>
#include <QUdpSocket>

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    QUdpSocket udpSocket;
    QByteArray message = "Hello from udp client";

    QHostAddress destAddress = QHostAddress("127.0.0.1");
    quint16 destPort = 49153;
    udpSocket.writeDatagram(message, destAddress, destPort);

    return QCoreApplication::exec();
}
