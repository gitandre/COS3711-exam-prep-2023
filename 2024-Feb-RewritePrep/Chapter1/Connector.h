//
// Created by User on 2/9/2024.
//

#ifndef CHAPTER1_CONNECTOR_H
#define CHAPTER1_CONNECTOR_H

#include <QObject>
#include <QDebug>
#include <iostream>
#include "Sender.h"
#include "Reciever.h"

class Connector : public QObject {
Q_OBJECT

public:
    Sender *m_s;
    Receiver *m_r;

    Connector(Sender *s, Receiver *r) : m_s(s), m_r(r) {

        QObject::connect(m_s, &Sender::mySignal, r, &Receiver::mySlot);


    }


};

#endif //CHAPTER1_CONNECTOR_H
