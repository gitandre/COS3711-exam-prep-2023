//
// Created by User on 2/9/2024.
//

#ifndef CHAPTER1_RECIEVER_H
#define CHAPTER1_RECIEVER_H

#include <QObject>
#include <QDebug>
#include <iostream>

using namespace std;

class Receiver : public QObject {
Q_OBJECT

public slots:

    void mySlot(std::string value) {

        QObject* obj = sender();

        cout << "\nReceiver my slot received = " << value << " from " << obj->metaObject()->className() << endl;
    }
};


#endif //CHAPTER1_RECIEVER_H
