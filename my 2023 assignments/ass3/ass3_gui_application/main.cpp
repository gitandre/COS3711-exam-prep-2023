#include <QApplication>
#include <QPushButton>
#include "MyStoreApp.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    qRegisterMetaType<MyTransactionLineItem>("MyTransactionLineItem");
    MyStoreApp mainWindow;
    mainWindow.show();

    return QApplication::exec();
}
