#include <QApplication>
#include <QPushButton>
#include "dbManager/DatabaseManager.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {

    // instantiate the singleton dbManager and create an alias or reference using the '&'
    DatabaseManager &dbManager = DatabaseManager::getInstance();

    // For all object types get the next id (Students, Advisors, Modules, Degrees)
    for (int i = 0; i < DatabaseManager::COUNT; ++i) {
        auto objectType = static_cast<DatabaseManager::ObjectType>(i);
        string enumString = DatabaseManager::enumToString(objectType);

        cout << enumString + ": " << endl;

        int nextId = DatabaseManager::getNextIdForObject(objectType);
        cout << "next Id for " + enumString + " is " << nextId << endl;
    }


    QApplication a(argc, argv);
    QPushButton button("Hello world!", nullptr);
    button.resize(200, 100);
    button.show();
    return QApplication::exec();
}
