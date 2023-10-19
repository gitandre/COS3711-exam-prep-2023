#include <QApplication>
#include <QPushButton>
#include "dbManager/DatabaseManager.h"
#include "Student.h"
#include "Advisor.h"
#include <iostream>
#include <QMainWindow>
#include <QStatusBar>
#include <QDebug>
#include <QMessageBox>
#include "SolutionObjectType.h"
#include "LogReceiverWidget.h"
#include <QString>
#include <QVBoxLayout>
#include <QObject>
#include <QTextEdit>

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

bool testing( QMainWindow &mainWindow) {// testing Student and Student

    bool res = false;


    Advisor a1("Advisor One", "advisor_one@test.com");
    a1.setObjectName("a1");
    cout << a1.objectName().toStdString() << endl;
    cout << a1.getId() << endl;
    cout << a1.getName().toStdString() << endl;
    cout << a1.getObjectType() << endl;

    bool created3 = DatabaseManager::getInstance().createNew(&a1);// pass in address
    if (created3) {
        res = true;
        mainWindow.statusBar()->showMessage("Success: Test record Advisor creation OK");
    } else {
        res = false;
        mainWindow.statusBar()->showMessage("Error: Test record Advisor creation FAILED");
    }

    if(res){
        Student s0;
        s0.setObjectName("default constructor student");

        Student s1("Student One", "student_one@test.com");
        s1.setObjectName("s1");
        cout << s1.objectName().toStdString() << endl;

        cout << s1.getId() << endl;
        cout << s1.getName().toStdString() << endl;
        cout << s1.getObjectType() << endl;

        bool created2 = DatabaseManager::getInstance().createNew(&s1); // pass in address
        if (created2) {
            res = true;
            mainWindow.statusBar()->showMessage("Success: Test record Student creation OK");
        } else {
            res = false;
            mainWindow.statusBar()->showMessage("Error: Test record Student creation FAILED");
        }
    }

    return res;
}

int main(int argc, char *argv[]) {

    if (startDatabaseManager()) {

        QApplication a(argc, argv);

        // Set mainWindow stuff
        QMainWindow mainWindow;
        mainWindow.setWindowTitle("Student Manager Solution");
        mainWindow.statusBar()->showMessage("Success: DatabaseManager started OK", 5000);
        mainWindow.resize(800, 600);

        auto *centralWidget = new QWidget();  // Create a central widget
        auto *layout = new QVBoxLayout(); // Create a QVBoxLayout

        auto *logReceiver = new LogReceiverWidget();

//        logReceiver->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);


//         example of create as ptr and connect and do something...
        auto *button = new QPushButton("Click to test DBManager", &mainWindow);
        button->setGeometry(50, 50, 250, 40);
//        button->setSizePolicy(QSizePolicy::w, QSizePolicy::Preferred);
        // Connect the button's clicked signal to a lambda function
        QObject::connect(button, &QPushButton::clicked, [&]() {
            if(testing(mainWindow)){
//                QMessageBox::information(&mainWindow, "Success: DB Manager", "tests passed OK :)");
//                button->hide();
            } else {
                QMessageBox::warning(&mainWindow, "Error: DB Manager", "tests failed :(");
                button->setText("Click again to re-test");
            }
        });

        layout->addWidget(button);
        layout->addWidget(logReceiver);
        centralWidget->setLayout(layout);
        mainWindow.setCentralWidget(centralWidget);

        DatabaseManager& dbManager = DatabaseManager::getInstance();
        QObject::connect(&dbManager, &DatabaseManager::sendMessage, logReceiver, &LogReceiverWidget::getMessage);


        mainWindow.show();
        return QApplication::exec();

    } else {
        return -1;
    }
}
