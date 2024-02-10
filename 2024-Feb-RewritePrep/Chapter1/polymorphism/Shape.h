//
// Created by User on 2/10/2024.
//

#ifndef CHAPTER1_SHAPE_H
#define CHAPTER1_SHAPE_H

#include <QObject>
#include <QDebug>
#include <string>

class Shape: QObject  {
    Q_OBJECT

public:

    virtual void Draw(){
        qDebug() << "\nI am a shape";
        qDebug() << m_privateInt;
        qDebug() << m_protectedInt;
    }
private:
    int m_privateInt = 42;

protected:
    int m_protectedInt = 69;
};

#endif //CHAPTER1_SHAPE_H
