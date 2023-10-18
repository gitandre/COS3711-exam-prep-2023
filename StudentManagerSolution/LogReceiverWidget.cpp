//
// Created by User on 10/18/2023.
//

#include "LogReceiverWidget.h"

LogReceiverWidget::LogReceiverWidget(QWidget *parent) {

    textedit = new QTextEdit(this);
    textedit->setText("Logs will appear here");
    textedit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    textedit->resize(800,300);
}

void LogReceiverWidget::getMessage(QString message) {
    textedit->setText(message);
}
