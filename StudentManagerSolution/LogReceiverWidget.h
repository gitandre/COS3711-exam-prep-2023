//
// Created by User on 10/18/2023.
//

#ifndef STUDENTMANAGERSOLUTION_LOGRECEIVERWIDGET_H
#define STUDENTMANAGERSOLUTION_LOGRECEIVERWIDGET_H

#include <QWidget>
#include <QTextEdit>
#include <QObject>

class LogReceiverWidget : public QWidget {
Q_OBJECT

public:
    explicit LogReceiverWidget(QWidget *parent = nullptr);


public slots:

    void getMessage(QString message);

private:
    QTextEdit *textedit;
};


#endif //STUDENTMANAGERSOLUTION_LOGRECEIVERWIDGET_H
