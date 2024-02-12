#include "MainWindow.h"
#include <QTextEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QUdpSocket>
#include <QHostAddress>

// MainWindow and UI setup + connect signal
MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent) {

    setWindowTitle("UDP Transactions Receiver client");

    // Create UI
    textEdit = new QTextEdit(this);
    textEdit->setReadOnly(true);
    textEdit->setStyleSheet("QTextEdit { background-color: black; color: lime; }");
    textEdit->setText("Listening for transactions via UDP...");

    clearButton = new QPushButton("Clear", this);

    QVBoxLayout * layout = new QVBoxLayout;
    layout->addWidget(textEdit);
    layout->addWidget(clearButton);

    QWidget * centralWidget = new QWidget(this);
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);

    // Create UDP socket
    udpSocket = new QUdpSocket(this);

    if (!udpSocket->bind(QHostAddress("127.0.0.1"), 49153)) {
        qDebug() << "Error: " << udpSocket->errorString();
    } else {
        qDebug() << "Bind OK";
    }

    // Connect the signal to read datagrams
    connect(udpSocket, &QUdpSocket::readyRead, this, &MainWindow::readPendingDatagrams);

    // Connect clear button
    connect(clearButton, &QPushButton::clicked, textEdit, &QTextEdit::clear);

    // Set main window size
    resize(1024, 768);
}

// Destructor
MainWindow::~MainWindow() {
    delete udpSocket;
}

// Read any pending UDP datagrams
void MainWindow::readPendingDatagrams() {

    textEdit->clear();

    while (udpSocket->hasPendingDatagrams()) {
        QByteArray datagram;
        datagram.resize(udpSocket->pendingDatagramSize());

        qint64 bytesRead = udpSocket->readDatagram(datagram.data(), datagram.size());
        if (bytesRead == -1) {
            qDebug() << "error: " << udpSocket->errorString();
        } else if (bytesRead == 0) {
            qDebug() << "Datagram is empty";
        }

        QString msg = QString::fromUtf8(datagram);
        textEdit->append(msg);
    }
}
