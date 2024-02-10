//
// Created by User on 2/9/2024.
//

#ifndef CHAPTER1_SENDER_H
#define CHAPTER1_SENDER_H

#include <QObject>
#include <QDebug>
#include "SingletonLogger/SingletonLogger.h"

class Sender : public QObject {
Q_OBJECT

    static int generateRandomNumber(int a = 1, int b = 100);

public:
    Sender(){
    }
    void sendSomething();

signals:

    void mySignal( std::string val);

};


#endif //CHAPTER1_SENDER_H
