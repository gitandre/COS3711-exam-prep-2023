#include <QCoreApplication>
#include <QTcpSocket>
#include <QHostAddress>
#include <iostream>

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);


    int port = 8083;
    QTcpSocket socket;
    socket.connectToHost(QHostAddress::LocalHost, port);
    qDebug() << QHostAddress::LocalHost;

    if (!socket.waitForConnected(5000)) {
        std::cerr << "Failed to connect to host." << std::endl;
        return -1;
    }

    // Send a message to the server
    const char *message = "Hello, server from client :)";
    socket.write(message);

    if (!socket.waitForBytesWritten(5000)) {
        std::cerr << "Failed to write bytes to socket." << std::endl;
        return -1;
    }

    // Wait for a response from the server
    if (!socket.waitForReadyRead(5000)) {
        std::cerr << "Failed to read from socket." << std::endl;
        return -1;
    }

    QByteArray responseData = socket.readAll();
    std::cout << "Server responded: " << responseData.toStdString() << std::endl;

    // Close the connection
    socket.disconnectFromHost();

    return a.exec();
}
