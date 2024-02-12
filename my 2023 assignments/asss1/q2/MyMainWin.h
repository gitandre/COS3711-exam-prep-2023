#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QListView>
#include <QDateEdit>
#include <QComboBox>
#include "MyStaffMemberModel.h"

// The MainWindow class
class MyMainWin : public QMainWindow {
Q_OBJECT

public:
    MyMainWin(QWidget *p = nullptr);

    ~MyMainWin();

private slots:

    void writeStaffMembersToFile(MyStaffMemberModel *myModel);

    void addNewStaffMember();

    void editExistingStaffMember();

    void delAStaffMember();

private:
    MyStaffMemberModel *mySMModel;

    QLineEdit *nameField;
    QDateEdit *dateField;
    QComboBox *addQComboBox;

    QPushButton *exportFileBtn;
    QListView *myListView;

    QPushButton *addBtn;
    QPushButton *editBtn;
    QPushButton *delbtn;

    void SetupLayout();
};

#endif
