#include <QApplication>
#include "MyMainWindow.h"

// Main entry point
int main(int argc, char *argv[])
{
    // creat the Q app
    QApplication myApp(argc, argv);

    // create a new main window
    MyMainWindow myMainWindow;
    myMainWindow.setWindowTitle("COS3711 - Assignment 2 - Question 2 and 3");
    myMainWindow.show();

    // run the Q app
    return myApp.exec();
}