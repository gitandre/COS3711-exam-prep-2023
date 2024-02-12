//Name: Bobby Nooba | Student Number: 666123 | Assignment 1 Unique number: 724933 | Question 1
//----------------------------------------------------------------------------------------------------------------------
#include "MyMainWin.h"
#include <QVBoxLayout>
#include <iostream>
#include <QLineEdit>
#include <QDate>
#include <QLabel>
#include <QMessageBox>
#include <QFileDialog>
#include "MyStaffMember.h"
#include "QDebug"

MyMainWin::MyMainWin(QWidget *p)
        : QMainWindow(p),
          nameField(new QLineEdit("")),
          dateField(new QDateEdit()),
          addQComboBox(new QComboBox()),
          addBtn(new QPushButton("Add")),
          editBtn(new QPushButton("Edit")),
          delbtn(new QPushButton("Delete")),
          exportFileBtn(new QPushButton("Export to file...")),
          myListView(new QListView),
          mySMModel(new MyStaffMemberModel(this)) {

    // Setup for widgets
    QDate today = QDate::currentDate();
    dateField->setDate(today);

    addQComboBox->addItem(MyStaffMember::getStringFromAppType(AppTypeEnum::Contract));
    addQComboBox->addItem(MyStaffMember::getStringFromAppType(AppTypeEnum::PartTime));
    addQComboBox->addItem(MyStaffMember::getStringFromAppType(AppTypeEnum::Permanent));

    // Set up the layouts
    SetupLayout();

    // Connect button clicks to functions
    connect(addBtn, &QPushButton::clicked, this, &MyMainWin::addNewStaffMember);
    connect(editBtn, &QPushButton::clicked, this, &MyMainWin::editExistingStaffMember);
    connect(delbtn, &QPushButton::clicked, this, &MyMainWin::delAStaffMember);
    QObject::connect(exportFileBtn, &QPushButton::clicked, [=]() {
        MyMainWin::writeStaffMembersToFile(mySMModel);
    });
}

void MyMainWin::SetupLayout() {

    //Central widget and sub layouts
    QWidget * centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    QVBoxLayout * mainLayout = new QVBoxLayout;

    QVBoxLayout * subLayoutHeader = new QVBoxLayout;
    QHBoxLayout * subLayoutH = new QHBoxLayout;
    QVBoxLayout * subLayoutV = new QVBoxLayout;

    // Add header and instructions
    subLayoutHeader->addWidget(
            new QLabel("Enter a name, birth date and position type. Then click Add"));

    // Add a line separator
    QFrame * line = new QFrame;
    line->setFrameShape(QFrame::HLine);
    line->setFrameShadow(QFrame::Sunken);
    subLayoutHeader->addWidget(line);

    // Add horizontal widgets
    subLayoutH->addWidget(new QLabel(""));
    subLayoutH->addWidget(new QLabel("Name"));
    subLayoutH->addWidget(nameField);
    subLayoutH->addWidget(new QLabel("Birth Date"));
    subLayoutH->addWidget(dateField);
    subLayoutH->addWidget(new QLabel("Type"));
    subLayoutH->addWidget(addQComboBox);
    subLayoutH->addWidget(addBtn);

    // Add the vertical layout widgets
    myListView->setModel(mySMModel);
    subLayoutV->addWidget(myListView);
    exportFileBtn->setFixedWidth(200);
    subLayoutV->addWidget(exportFileBtn);
    subLayoutV->addWidget(new QLabel("© 2023 | Name: Bobby Nooba | Student Number: 666123 | Assignment 1 Unique number: 724933 | Question 1"));

    // Bind to layouts
    mainLayout->addLayout(subLayoutHeader);
    mainLayout->addLayout(subLayoutH);
    mainLayout->addLayout(subLayoutV);
    centralWidget->setLayout(mainLayout);
}

MyMainWin::~MyMainWin() {}

int getAge(QDate birthdate) {
    QDate cDate = QDate::currentDate();

    int yearsGoneBy = birthdate.year() - cDate.year();

    if (birthdate.month() > cDate.month() ||
        (birthdate.month() == cDate.month() && birthdate.day() > cDate.day())) {
        yearsGoneBy--;
    }

    return yearsGoneBy * -1;
}

void MyMainWin::addNewStaffMember() {

    // validation checking
    if (!nameField->text().isEmpty() && nameField->text().size() >= 3) {

        // Check age -> assuming must be 18 years or older for the position
        int age = getAge(dateField->date());
        if (age >= 18) {

            // If all validations passed then add member
            MyStaffMember newMember(nameField->text(), dateField->date(),
                                    MyStaffMember::getTypeFromString(addQComboBox->currentText()));
            mySMModel->addStaffMember(newMember);

            //Reset/clear all fields
            nameField->clear();
            dateField->setDate(QDate::currentDate());
            addQComboBox->setCurrentIndex(0);
            nameField->setFocus();

        } else {
            // show validation message
            QMessageBox::critical(nullptr, "Validation Error",
                                  "Please enter a valid birth date, must be 18 years or older");
        }
    } else {
        // show validation message
        QMessageBox::critical(nullptr, "Validation Error", "Please enter a name, greater than or equal to 3 letters");
    }
}

void MyMainWin::editExistingStaffMember() {
    // Not implemented yet
    std::cout << "edit..." << std::endl;
}

void MyMainWin::delAStaffMember() {
    // Not implemented yet
    std::cout << "delete..." << std::endl;
}

void MyMainWin::writeStaffMembersToFile(MyStaffMemberModel *myModel) {

    // Prompt user for dir/path to save file
    QString fPath = QFileDialog::getSaveFileName(nullptr, "Export Staff Members to a file", "",
                                                 "Text Files (*.txt);;All Files (*)");

    // If user selected a path and did not cancel
    if (!fPath.isEmpty()) {

        // Open a file and stream
        QFile file(fPath);

        // If cannot open a temp file and stream...
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
            QMessageBox::critical(nullptr, "IO Error", "Could not open temp file and stream");
        else {

            // ... else carry on
            QTextStream out(&file);

            // For each item write the row to file
            int rowCount = myModel->rowCount();
            for (int row = 0; row < rowCount; ++row) {

                QString rowAsString = myModel->data(myModel->index(row)).toString();
                out << rowAsString << "\n";
            }

            // Close the file and show success message and file path details
            file.close();

            QMessageBox msgBox;
            msgBox.setWindowTitle("Export OK");
            msgBox.setText("Your file was exported successfully to " + fPath);
            msgBox.setIcon(QMessageBox::Information);
            msgBox.setStandardButtons(QMessageBox::Ok);
            msgBox.exec();
        }
    }
}