//
// Created by User on 10/20/2023.
//

#ifndef TAKENOTE_CHECKLISTNOTEFACTORY_H
#define TAKENOTE_CHECKLISTNOTEFACTORY_H
#include <QObject>
#include "Note.h"
#include "NoteFactory.h"

class ChecklistNoteFactory : public NoteFactory {
    Q_OBJECT
public:
    Note* createNote(QString title, QString content) override {
        return new Note(title, content + " (Checklist Note)", this);
    }
};


#endif //TAKENOTE_CHECKLISTNOTEFACTORY_H
