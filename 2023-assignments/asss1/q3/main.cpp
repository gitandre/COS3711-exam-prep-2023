//Name: Bobby Nooba | Student Number: 666123 | Assignment 1 Unique number: 724933 | Question 3
//----------------------------------------------------------------------------------------------------------------------
// Assignment 1 - Question 3
//Use Qt’s model/view framework to store and display music album information. The following
//information should be stored in your own custom model (that inherits from
//QAbstractTableModel):
//- composer,
//- album name,
//-cost (stored as a double, and
//- a rating (out of 100, store as an int).

//Your sub-classed model should be a well-behaved, editable model (and you will need to add all
//the necessary functions to your model). The information should be displayed in a standard
//QTableView.

//The following functionality should be included.
// There should be a header row.
// The user should be able to add data to the model.
// The replacement value should always display the cents (even as .00).

#include <QApplication>
#include "MyMainWin.h"

// The main entry point for my application------------------------------------------------------------------------------
int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Main Window Widget
    MyMainWin mw;

    // Set window size and title
    mw.setGeometry(200, 200, 1200, 600);
    mw.setWindowTitle("Assignment 1 - Question 3");

    mw.show();

    return app.exec(); // Run the app loop
}
