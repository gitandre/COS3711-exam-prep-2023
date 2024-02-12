#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QUdpSocket>
#include <QTextEdit>
#include <QPushButton>

// MainWindow header
class MainWindow : public QMainWindow {
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

private slots:

    void readPendingDatagrams();

private:
    QUdpSocket *udpSocket;
    QTextEdit *textEdit;
    QPushButton *clearButton;
};

#endif