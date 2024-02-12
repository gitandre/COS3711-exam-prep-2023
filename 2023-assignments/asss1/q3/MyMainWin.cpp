//Name: Bobby Nooba | Student Number: 666123 | Assignment 1 Unique number: 724933 | Question 3
//----------------------------------------------------------------------------------------------------------------------
#include "MyMainWin.h"
#include <QVBoxLayout>
#include <iostream>
#include <QLineEdit>
#include <QLabel>
#include <QMessageBox>
#include <QSpinBox>
#include <QHeaderView>

// Main window implementation------------------------------------------------------------------------------------------
MyMainWin::MyMainWin(QWidget *p)
        : QMainWindow(p),
          composerField(new QLineEdit("")),
          albumField(new QLineEdit("")),
          priceSpinBox(new QDoubleSpinBox()),
          ratingSpinBox(new QSpinBox()),
          addBtn(new QPushButton("Add")),
          myTableView(new QTableView),
          model(new MyAlbumModel(this)) {

    // Set up the layouts
    SetupLayout();

    // Connect button clicks to functions
    connect(addBtn, &QPushButton::clicked, this, &MyMainWin::addNewAlbum);

}

void MyMainWin::addNewAlbum() {

    //validation checking - composer
    if (!composerField->text().isEmpty() && composerField->text().size() >= 1) {

        // Check album
        if (!albumField->text().isEmpty() && albumField->text().size() >= 1) {

            // If all validations passed then add album
            MyAlbum album{composerField->text(), albumField->text(), priceSpinBox->value(), ratingSpinBox->value()};
            model->addAlbum(album);

            //Reset/clear all fields
            composerField->clear();
            albumField->clear();
            priceSpinBox->clear();
            ratingSpinBox->clear();
            composerField->setFocus();

        } else {
            // show validation message
            QMessageBox::critical(nullptr, "Validation Error",
                                  "Please enter a valid album, must be 1 chars or longer");
        }
    } else {
        // show validation message
        QMessageBox::critical(nullptr, "Validation Error", "Please enter a valid composer, must be 1 chars or longer");
    }
}

void MyMainWin::SetupLayout() {

    //Central widget and sub layouts
    QWidget * centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    QVBoxLayout * mainLayout = new QVBoxLayout;

    QVBoxLayout * subLayoutHeader = new QVBoxLayout;
    QHBoxLayout * subLayoutH = new QHBoxLayout;
    QVBoxLayout * subLayoutV = new QVBoxLayout;

    //Set range for spinboxes
    ratingSpinBox->setRange(0, 100);
    priceSpinBox->setRange(0.00, 100000.00);

    // Add header and instructions
    subLayoutHeader->addWidget(
            new QLabel("Enter a composer, album title, replacement price and rating out of 100, then click Add"));


    // Add a line separator
    QFrame * line = new QFrame;
    line->setFrameShape(QFrame::HLine);
    line->setFrameShadow(QFrame::Sunken);
    subLayoutHeader->addWidget(line);

    // Add horizontal widgets
    subLayoutH->addWidget(new QLabel(""));
    subLayoutH->addWidget(new QLabel("Composer/Artist"));
    subLayoutH->addWidget(composerField);
    subLayoutH->addWidget(new QLabel("Album Name"));
    subLayoutH->addWidget(albumField);
    subLayoutH->addWidget(new QLabel("Price"));
    subLayoutH->addWidget(priceSpinBox);
    subLayoutH->addWidget(new QLabel("Rating"));
    subLayoutH->addWidget(ratingSpinBox);
    subLayoutH->addWidget(addBtn);

    // Add an example row
    MyAlbum album1{"The Beatles", "The White Album (1968)", 19939.18, 99};
    model->addAlbum(album1);

    //Set model and column stretch
    myTableView->setModel(model);
    QHeaderView* horizontalHeader = myTableView->horizontalHeader();
    horizontalHeader->setSectionResizeMode(QHeaderView::Stretch);

    subLayoutV->addWidget(myTableView);

    subLayoutV->addWidget(new QLabel("© 2023 | Name: Bobby Nooba | Student Number: 666123 | Assignment 1 Unique number: 724933 | Question 3"));

    // Bind to layouts
    mainLayout->addLayout(subLayoutHeader);
    mainLayout->addLayout(subLayoutH);
    mainLayout->addLayout(subLayoutV);
    centralWidget->setLayout(mainLayout);
}

MyMainWin::~MyMainWin() {}
