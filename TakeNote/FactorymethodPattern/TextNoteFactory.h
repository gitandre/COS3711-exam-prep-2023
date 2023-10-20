//
// Created by User on 10/20/2023.
//

#ifndef TAKENOTE_TEXTNOTEFACTORY_H
#define TAKENOTE_TEXTNOTEFACTORY_H

#include <QObject>
#include "NoteFactory.h"

class TextNoteFactory : public NoteFactory {
    Q_OBJECT
public:
    Note* createNote(QString title, QString content) override {
        return new Note(title, content + " (Text Note)", this);
    }
};


#endif //TAKENOTE_TEXTNOTEFACTORY_H
