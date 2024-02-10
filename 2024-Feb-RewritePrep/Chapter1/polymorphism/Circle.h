//
// Created by User on 2/10/2024.
//

#ifndef CHAPTER1_CIRCLE_H
#define CHAPTER1_CIRCLE_H

#include <QObject>
#include <QDebug>
#include <string>
#include "ShapePureVirtual.h"

class Circle : public Shape {

public:

    void Draw() override {
        qDebug() << "\nI am a circle";
        qDebug() << m_protectedInt;
    }
};

#endif //CHAPTER1_CIRCLE_H
