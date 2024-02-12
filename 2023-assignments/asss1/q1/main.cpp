//Name: Bobby Nooba | Student Number: 666123 | Assignment 1 Unique number: 724933 | Question 1
//----------------------------------------------------------------------------------------------------------------------
//Assignment 1 - Question 1

//Write an application that can be used to keep a list of staff member details. Each staff member data should include
// the following:
// A name,
// A birth date, and
// A staff appointment type (one of permanent, part-time, or contract, stored and handled as an
//enum). = Done

//Include all necessary getter and setter functions. An additional getter can be used to return the
//        appointment type as a QString. = Done

//The application should allow a user to enter details via a GUI. Also, once a staff member’s details
//are entered, they should be saved to a list/container in the application. The user should be able
//        to write this list to file (in any acceptable, human-readable format) when needed. = Done

//Ensure that you adhere to basic design principles and avoid any anti-patterns in the design of
//        your solution = Done

#include <QApplication>
#include "MyMainWin.h"

// Main entry point for program
int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Main Window Widget
    MyMainWin mw;

    // Set window sie and title
    mw.setGeometry(200, 200, 800, 600);
    mw.setWindowTitle("Assignment 1 - Question 1");

    mw.show();

    return app.exec();
}