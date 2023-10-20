//
// Created by User on 10/20/2023.
//

#ifndef TAKENOTE_NOTE_H
#define TAKENOTE_NOTE_H

#include <QObject>
#include <QString>

class Note: public QObject {
Q_OBJECT

public:
    QString title;
    QString content;

    Note(): QObject(nullptr){}
    Note(QString title, QString content, QObject* parent = nullptr) : QObject(parent), title(title), content(content) {}
};


#endif //TAKENOTE_NOTE_H
