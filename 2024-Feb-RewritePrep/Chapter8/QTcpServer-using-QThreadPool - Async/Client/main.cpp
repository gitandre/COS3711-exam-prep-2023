#include <QCoreApplication>
#include <QTcpSocket>
#include <QDebug>

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    QTcpSocket socket;

    // Connect to the server
    socket.connectToHost(QHostAddress::LocalHost, 8083); // Use the correct IP and port

    QObject::connect(&socket, &QTcpSocket::connected, [&socket]() {
        qDebug() << "Connected to server. Sending message...";
        socket.write("Hello, server! from client 1 - are you async?"); // Send a message to the server
    });

    QObject::connect(&socket, &QTcpSocket::bytesWritten, [&socket]() {
        qDebug() << "Message sent. Waiting for response...";
    });

    QObject::connect(&socket, &QTcpSocket::readyRead, [&socket]() {
        // Read the response from the server
        QByteArray responseData = socket.readAll();
        qDebug() << "Response from server:" << responseData;
        socket.disconnectFromHost(); // Optionally disconnect after receiving the response
    });

    qInfo() << "Client started OK";

    return a.exec();
}
