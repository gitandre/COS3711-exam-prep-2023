//Assignment 1 - Question 2 - extends question 1
//
//Taking Question 1 a step further, make all the getters and setters (including any toString()
//functions) that give access to the data members name, birthdate and staff type private.
//
// Then make the necessary changes so that your application uses reflective programming techniques to
//access the data members in the object that holds the staff data when writing to file.

//Note that you cannot assume that you know beforehand how many properties there are, what
//they are called, or of what type they are. You will need to find a way of handling the enum, though
//as you (and in this case you can accept that you know that there is an enum, but you need to find
//its values in some way); also, you will have to move away from using a QString for the enum
//here.

//HINT: You will need to use QVariant.
//----------------------------------------------------------------------------------------------------------------------

#include <QApplication>
#include "MyMainWin.h"

// Main entry point for program
int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Main Window Widget
    MyMainWin mw;

    // Set window sie and title
    mw.setGeometry(200, 200, 800, 600);
    mw.setWindowTitle("Assignment 1 - Question 2");

    mw.show();

    return app.exec();
}