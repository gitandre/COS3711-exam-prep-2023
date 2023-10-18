#include <QApplication>
#include <QPushButton>
#include "dbManager/DatabaseManager.h"
#include "Student.h"
#include "Advisor.h"
#include <iostream>
#include <QMainWindow>
#include <QStatusBar>
#include <QDebug>
#include "SolutionObjectType.h"
using namespace std;

bool startDatabaseManager() {// instantiate the singleton dbManager and create an alias or reference using the '&'

    bool result = false;

    DatabaseManager::getInstance(); // instantiate singleton

    int dbCounter = 0;
    int enumCount = SolutionObjectType::COUNT;
    cout << "enumCount = " << enumCount << endl;
    // For all object types get the next id (Students, Advisors, Modules, Degrees)
    for (int i = 0; i < enumCount; ++i) {
        auto objectType = static_cast<SolutionObjectType>(i);
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

    if (dbCounter != SolutionObjectType::COUNT) {
        qFatal() << "Fatal Error: DatabaseManager could not start";
    } else {
        result = true;
        qDebug() << "Success: DatabaseManager started OK";
    }

    return result;
}

void testing(const QMainWindow &mainWindow) {// testing Student and Student

    Advisor a1("Addy Bloggs", "addy@test.com");
    cout << a1.getId() << endl;
    cout << a1.getName().toStdString() << endl;
    cout << a1.getObjectType() << endl;

    bool created3 = DatabaseManager::getInstance().createNew(a1);
    if (created3) {
        mainWindow.statusBar()->showMessage("Success: Test record Advisor creation OK");
    } else {
        mainWindow.statusBar()->showMessage("Error: Test record Advisor creation FAILED");
    }

    Student s1("Bloo", "Bloo@test.com");
    cout << s1.getId() << endl;
    cout << s1.getName().toStdString() << endl;
    cout << s1.getObjectType() << endl;

    bool created2 = DatabaseManager::getInstance().createNew(s1);
    if (created2) {
        mainWindow.statusBar()->showMessage("Success: Test record Student creation OK");
    } else {
        mainWindow.statusBar()->showMessage("Error: Test record Student creation FAILED");
    }
}

int main(int argc, char *argv[]) {

    if (startDatabaseManager()) {

        QApplication a(argc, argv);

        // Set mainWindow stuff
        QMainWindow mainWindow;
        mainWindow.setWindowTitle("Student Manager Solution");
        mainWindow.statusBar()->showMessage("Success: DatabaseManager started OK", 5000);
        mainWindow.resize(800, 600);

        //testing
        testing(mainWindow);


        mainWindow.show();
        return QApplication::exec();

    } else {
        return -1;
    }
}
