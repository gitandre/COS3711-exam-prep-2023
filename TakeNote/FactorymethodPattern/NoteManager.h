//
// Created by User on 10/20/2023.
//

#ifndef TAKENOTE_NOTEMANAGER_H
#define TAKENOTE_NOTEMANAGER_H

#include <QCoreApplication>
#include <QDebug>
#include <QString>
#include <QVector>
#include <QObject>
#include "Note.h"
#include "NoteFactory.h"
#include "../Singleton/Logger.h"

class NoteManager : public QObject {
    Q_OBJECT

    NoteFactory* factory;
    Logger* logger;

public:
    QVector<Note*> notes;

    NoteManager(NoteFactory* factory, QObject* parent = nullptr) : QObject(parent), factory(factory) {
        logger = Logger::getInstance();  // Initialize logger here
    }

    void createNote(QString title, QString content) {
        Note* newNote = factory->createNote(title, content);
        notes.append(newNote);
        logger->logEvent("Note created: " + newNote->title);
    }

    void listNotes() {
        logger->logEvent("Listing all notes...");
        for (const auto& note : notes) {
            logger->logEvent(note->title);
        }
    }

};


#endif //TAKENOTE_NOTEMANAGER_H
