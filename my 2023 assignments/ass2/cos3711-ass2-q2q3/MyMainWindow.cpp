#include <QMenuBar>
#include <QMessageBox>
#include <QFileDialog>
#include <QXmlStreamWriter>
#include <QDesktopServices>
#include <QUrl>
#include <iostream>
#include "MyMainWindow.h"
#include "MyStockDialog.h"
#include "ConfectReadingMatFactory.h"
#include "XMLViewerDialog.h"

MyMainWindow::MyMainWindow(QWidget *parent) :
        QMainWindow(parent),
        stocklistWidget(new QListWidget(this))
{
    setCentralWidget(stocklistWidget);
    resize(800, 600);

    // Setup menu items---------------------------------------------------------------------------------------------------
    // Stock
    QMenu* stockMenu = menuBar()->addMenu(tr("Stock"));
    QAction* addStockAction = stockMenu->addAction(tr("Add stock item"));

    // List
    QMenu* listMenu = menuBar()->addMenu(tr("List Stock"));
    QAction* listConfectionaryAction = listMenu->addAction(tr("List Confectionary Items"));
    QAction* listReadingMaterialAction = listMenu->addAction(tr("List Reading Material Items"));

    // XML - specific to question 3
    QMenu* xmlMenu = menuBar()->addMenu(tr("XML"));
    QAction* writeXmlAction = xmlMenu->addAction(tr("Write to XML"));

    // Slots and signals/actions
    connect(addStockAction, &QAction::triggered, this, &MyMainWindow::addStockItem);
    connect(listConfectionaryAction, &QAction::triggered, this, &MyMainWindow::listConfectionary);
    connect(listReadingMaterialAction, &QAction::triggered, this, &MyMainWindow::listReadingMaterial);
    // Connect new action - specific to question 3
    connect(writeXmlAction, &QAction::triggered, this, &MyMainWindow::writeToXml);

    // Show the initial/empty stock list
    updateMixedStockList();
}

// Destructor
MyMainWindow::~MyMainWindow()
{
    delete stocklistWidget;
}

// Add a new stock item of the 2 types
void MyMainWindow::addStockItem()
{

    MyStockDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {

        // Using the factory pattern to create confectionary or reading material
        ConfectReadingMatFactory factory;
        auto stock = factory.create(dialog.getType(), dialog.getItem(), dialog.getQuantity(), dialog.getExtra());

        if (auto confectionery = dynamic_cast<Confectionary*>(stock.get())) {
            confectioneries.append(*confectionery);
            QMessageBox::information(this, "Information", "Confectionary item saved OK");
        }
        else if (auto readingMaterial = dynamic_cast<ReadingMaterial*>(stock.get())) {
            readingMaterials.append(*readingMaterial);
            QMessageBox::information(this, "Information", "ReadingMaterial item saved OK");
        }
    }

    //Display all the stock items after a successful save
    updateMixedStockList();
}

void MyMainWindow::listConfectionary()
{
    // Show just confectionary items
    stocklistWidget->clear();
    populateListConfectionary();

}

void MyMainWindow::populateListConfectionary() {

    // Handle zero qty
    if (confectioneries.size() == 0){
        stocklistWidget->addItem("Confectionary Items: 0");
        return;
    }

    // Show just confectionary items -> by building a new list
    for(int i=0; i < confectioneries.size(); i++){
        stocklistWidget->addItem(confectioneries[i].toString());
    }
    stocklistWidget->show();
}

void MyMainWindow::listReadingMaterial()
{
    // Show just reading materials items
    stocklistWidget->clear();
    populateReadingMaterials();
}

void MyMainWindow::populateReadingMaterials() {

    // Handle zero qty
    if (readingMaterials.size() == 0){
        stocklistWidget->addItem("Reading Material Items: 0");
        return;
    }

    // Show just reading materials items -> by building a new list
    for(int i=0; i < readingMaterials.size(); i++){
        stocklistWidget->addItem(readingMaterials[i].toString());
    }
    stocklistWidget->show();
}

void MyMainWindow::updateMixedStockList() {

    // Show both types in one list for after a save
    stocklistWidget->clear();
    populateListConfectionary();
    populateReadingMaterials();
}

// Write the stock file to xml - Question 3 specific
void MyMainWindow::writeToXml()
{
    // Handle use-case if no stock items
    if (confectioneries.size() == 0 && readingMaterials.size() == 0){
        QMessageBox::warning(this, "Warning", "No stock items to write, please add items and try again!");
        return;
    }

    // Select a place to save the xml file
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save XML File"), "", tr("XML files (*.xml)"));

    std::cout << fileName.toStdString();
    // Handle if no file entered/selected
    if (fileName.isEmpty()) return;

    QFile file(fileName);
    if (!file.open(QFile::WriteOnly | QFile::Text)) {

        // Handle any errors associated with unable to open or write file
        QMessageBox::warning(this, "Warning", "Cannot write/open this file: " + file.errorString());
        return;
    }

    // Build the XML and create xml file
    QXmlStreamWriter xmlWriter(&file);
    buildXML(xmlWriter);

    file.close();

    // Handle any errors or show success message
    if (file.error()) {
        QMessageBox::warning(this, "Warning", "Cannot write this file: " + file.errorString());
    }
    else {
        QMessageBox::information(this, "Information", "Stock items exported to XML ok :)");


        // Open the file so the user can view it using a custom XMLViewer dialog
        XMLViewerDialog xmlViewer(fileName, this);
        xmlViewer.exec();
    }
}

// Build the xml - Question 3 specific
void MyMainWindow::buildXML(QXmlStreamWriter &xmlWriter) {

    // Set formatting to human-readable output/pretty
    xmlWriter.setAutoFormatting(true);

    xmlWriter.writeStartDocument();
    xmlWriter.writeStartElement("stockList");

    for (Confectionary c : confectioneries) {
        xmlWriter.writeStartElement("stockItem");
        xmlWriter.writeAttribute("type", "Confectionary");

        // Write elements
        xmlWriter.writeTextElement("item", c.getItem());
        xmlWriter.writeTextElement("quantity", QString::number(c.getQuantity()));
        xmlWriter.writeTextElement("weight", QString::number(c.getWeight()));

        // stockItem
        xmlWriter.writeEndElement();
    }

    for (ReadingMaterial rm : readingMaterials) {
        xmlWriter.writeStartElement("stockItem");
        xmlWriter.writeAttribute("type", "ReadingMaterial");

        // Write elemenets
        xmlWriter.writeTextElement("item", rm.getItem());
        xmlWriter.writeTextElement("quantity", QString::number(rm.getQuantity()));
        xmlWriter.writeTextElement("frequency", rm.getFrequency());

        // stockItem
        xmlWriter.writeEndElement();
    }

    // stockList
    xmlWriter.writeEndElement();

    // End the xml document
    xmlWriter.writeEndDocument();
}
