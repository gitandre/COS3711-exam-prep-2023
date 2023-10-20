#include <QCoreApplication>
#include <QDebug>
#include "FactorymethodPattern/NoteManager.h"
#include "FactorymethodPattern/TextNoteFactory.h"
#include "FactorymethodPattern/ChecklistNoteFactory.h"
#include "FactoryAbstractPattern/NormalModeFactory.h"
#include "FactoryAbstractPattern/AllCapsModeFactory.h"

int main(int argc, char *argv[]) {

    QCoreApplication a(argc, argv);

    // Create Logger instance and set the initial text mode to "Normal Mode"
    Logger* logger = Logger::getInstance();
    TextModeFactory* normalFactory = new NormalModeFactory();
    logger->setTextModeFactory(normalFactory);

    // Log the application start event in "Normal Mode"
    logger->logEvent("App started...");

    // Change the text mode to "All CAPS Mode"
    TextModeFactory* allCapsFactory = new AllCapsModeFactory();
    logger->setTextModeFactory(allCapsFactory);

    // Log a new event in "All CAPS Mode"
    logger->logEvent("App started...");


    TextNoteFactory textFactory;
    ChecklistNoteFactory checklistFactory;

    NoteManager textNoteManager(&textFactory);
    NoteManager checklistNoteManager(&checklistFactory);

    // Fake user actions for demonstration
    logger->setTextModeFactory(normalFactory);
    textNoteManager.createNote("Note1", "This is the first note.");
    checklistNoteManager.createNote("Note2", "This is the second note.");

    textNoteManager.listNotes();
    checklistNoteManager.listNotes();

    return QCoreApplication::exec();

}
