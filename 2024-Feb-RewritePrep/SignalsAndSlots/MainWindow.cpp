//
// Created by User on 2/9/2024.
//
#include "MainWindow.h"
#include <QDebug>

MainWindow::MainWindow() {
    // Example UI element
    QPushButton* button = new QPushButton("Press me", this);
    setCentralWidget(button);
    resize(400, 300);

    // Connect button's clicked signal to the custom slot
    connect(button, &QPushButton::clicked, this, [this]() {
        emit customSignal(42); // Emit a custom signal when the button is clicked
    });

    // Connect the custom signal to the custom slot
    connect(this, &MainWindow::customSignal, this, &MainWindow::customSlot);
}

void MainWindow::customSlot(int value) {
    qDebug() << "Custom slot received value:" << value;
}
