//Name: Bobby Nooba | Student Number: 666123 | Assignment 1 Unique number: 724933 | Question 3
//----------------------------------------------------------------------------------------------------------------------
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QListView>
#include <QDateEdit>
#include <QComboBox>
#include <QSpinBox>
#include <QTableView>
#include "MyAlbumModel.h"

// The MainWindow header class------------------------------------------------------------------------------------------------
class MyMainWin : public QMainWindow {
Q_OBJECT

public:
    //Constructor
    MyMainWin(QWidget *p = nullptr);

    ~MyMainWin();


private:
    // Private fields and functions
    MyAlbumModel *model;
    QLineEdit *composerField;
    QLineEdit *albumField;
    QDoubleSpinBox *priceSpinBox;
    QSpinBox *ratingSpinBox;
    QPushButton *addBtn;
    QTableView *myTableView;

    void SetupLayout();

    void addNewAlbum();
};

#endif
