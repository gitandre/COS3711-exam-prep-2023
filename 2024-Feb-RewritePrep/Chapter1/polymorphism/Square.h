//
// Created by User on 2/10/2024.
//

#ifndef CHAPTER1_SQUARE_H
#define CHAPTER1_SQUARE_H
#include <QObject>
#include <QDebug>
#include <string>
#include "ShapePureVirtual.h"
#include "Shape.h"

class Square : public ShapePureVirtual {

public:

    void Draw() override {
        qDebug() << "\nI am a square (ShapePureVirtual)";
        qDebug() << m_protectedInt;
    }
    void MustImplementOnChild(){
        qDebug() << "MustImplementOnChild";
    }
};
#endif //CHAPTER1_SQUARE_H
