#include <QApplication>
#include <QPushButton>
#include "dbManager/DatabaseManager.h"
#include <iostream>
#include <QMainWindow>
#include <QStatusBar>

using namespace std;

bool startDatabaseManager() {// instantiate the singleton dbManager and create an alias or reference using the '&'

    bool result = false;

    DatabaseManager::getInstance(); // instantiate singleton

    int dbCounter = 0;
    // For all object types get the next id (Students, Advisors, Modules, Degrees)
    for (int i = 0; i < DatabaseManager::COUNT; ++i) {
        auto objectType = static_cast<DatabaseManager::ObjectType>(i);
        QString enumString = DatabaseManager::enumToString(objectType);

        qDebug() << enumString << ": ";

        int nextId = DatabaseManager::getNextIdForObject(objectType);
        if (nextId > 0) {
            dbCounter++;
            qDebug() << "next Id for " << enumString << " is " << nextId;
        } else {
            qDebug("Error: nextId is 0 or less");
        }
    }

    if (dbCounter != DatabaseManager::COUNT) {
        qFatal() << "Fatal Error: DatabaseManager could not start";
    } else {
        result = true;
        qDebug() << "Success: DatabaseManager started OK";
    }

    return result;
}

int main(int argc, char *argv[]) {

    if (startDatabaseManager()) {

        QApplication a(argc, argv);

        // Set mainWindow stuff
        QMainWindow mainWindow;
        mainWindow.setWindowTitle("Student Manager Solution");
        mainWindow.statusBar()->showMessage("Success: DatabaseManager started OK", 5000);
        mainWindow.resize(800, 600);
        mainWindow.show();

        return QApplication::exec();
    } else {
        return -1;
    }
}
