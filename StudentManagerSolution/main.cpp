#include <QApplication>
#include <QPushButton>
#include "dbManager/DatabaseManager.h"

int main(int argc, char *argv[]) {

    // instantiate the singleton dbManager and create an alias or reference using the '&'
    DatabaseManager& dbManager = DatabaseManager::getInstance();

    QApplication a(argc, argv);
    QPushButton button("Hello world!", nullptr);
    button.resize(200, 100);
    button.show();
    return QApplication::exec();
}
