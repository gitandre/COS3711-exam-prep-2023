//
// Created by User on 2/10/2024.
//

#ifndef CHAPTER1_SHAPEPUREVIRTUAL_H
#define CHAPTER1_SHAPEPUREVIRTUAL_H

#include <QObject>
#include <QDebug>
#include <string>

using namespace std;

class ShapePureVirtual : QObject {
Q_OBJECT

public:
    // pure virtual makes class abstract
    virtual void MustImplementOnChild() = 0;

    virtual void Draw() {
        qDebug() << "I am a shape";
    }

    virtual ~ShapePureVirtual() {}

private:
    int m_privateInt = 42;

protected:
    int m_protectedInt = 69;
};


#endif //CHAPTER1_SHAPEPUREVIRTUAL_H
