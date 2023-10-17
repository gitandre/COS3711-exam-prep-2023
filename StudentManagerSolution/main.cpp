#include <QApplication>
#include <QPushButton>
#include "dbManager/DatabaseManager.h"
#include <iostream>

using namespace std;

bool startDatabaseManager() {// instantiate the singleton dbManager and create an alias or reference using the '&'

    bool result = false;
    DatabaseManager &dbManager = DatabaseManager::getInstance();

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

    if(startDatabaseManager()){
        QApplication a(argc, argv);
        QPushButton button("Hello world!", nullptr);
        button.resize(200, 100);
        button.show();
        return QApplication::exec();
    }
}
