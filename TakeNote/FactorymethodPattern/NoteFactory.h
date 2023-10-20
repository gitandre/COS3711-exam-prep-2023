//
// Created by User on 10/20/2023.
//

#ifndef TAKENOTE_NOTEFACTORY_H
#define TAKENOTE_NOTEFACTORY_H


#include <QObject>
#include "Note.h"

class NoteFactory : public QObject {
    Q_OBJECT
public:
    virtual Note* createNote(QString title, QString content) = 0;
};


#endif //TAKENOTE_NOTEFACTORY_H
