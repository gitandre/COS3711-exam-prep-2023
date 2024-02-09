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

    void mySlot(int value) {
        cout << value ;
    }
};


#endif //CHAPTER1_RECIEVER_H
