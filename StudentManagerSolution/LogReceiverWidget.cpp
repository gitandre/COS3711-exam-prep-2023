//
// Created by User on 10/18/2023.
//

#include "LogReceiverWidget.h"

LogReceiverWidget::LogReceiverWidget(QWidget *parent) {

    textedit = new QTextEdit(this);
    textedit->setText("Logs will appear here");
    textedit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    textedit->resize(780,250);
}

void LogReceiverWidget::getMessage(QString message) {

    logList->append(message);

    QString stringList = "";
    for(const auto& item : *logList){
        stringList = stringList + item + "\n";
    }
    textedit->setText(stringList);
    QScrollBar *scrollBar = textedit->verticalScrollBar();
    scrollBar->setValue(scrollBar->maximum());
}
