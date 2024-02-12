//
// Created by User on 2/9/2024.
//

#ifndef SIGNALSANDSLOTS_MAINWINDOW_H
#define SIGNALSANDSLOTS_MAINWINDOW_H
#include <QMainWindow>
#include <QPushButton>

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    MainWindow();

signals:
    void customSignal(int value);

public slots:
    void customSlot(int value);
};
#endif //SIGNALSANDSLOTS_MAINWINDOW_H
