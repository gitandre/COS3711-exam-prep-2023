#include "MyStoreApp.h"
#include "AddMyItemDialog.h"
#include "MyItemListDialog.h"
#include "MyTransactionFormDialog.h"
#include "MyTransactionTreeViewWidget.h"
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QApplication>
#include <QScreen>
#include <QGuiApplication>
#include <QFile>
#include <QDebug>
#include <QDomElement>
#include <QMessageBox>
#include <QUdpSocket>

void MyStoreApp::appendItemToXML(const MyItem &newItem) {
    QString appDir = QCoreApplication::applicationDirPath();
    QFile file(appDir + "/../MyItems.xml");

    QDomDocument doc;
    if (file.open(QIODevice::ReadOnly)) {
        if (doc.setContent(&file)) {
            file.close();
        }
    }

    // The root element
    QDomElement root = doc.documentElement();
    if (root.isNull()) {
        root = doc.createElement("items");
        doc.appendChild(root);
    }

    // The new item element
    QDomElement itemElement = doc.createElement("item");
    QDomElement nameElement = doc.createElement("name");
    QDomElement typeElement = doc.createElement("type");

    QDomText nameText = doc.createTextNode(newItem.name);
    QDomText typeText = doc.createTextNode(newItem.type);

    nameElement.appendChild(nameText);
    typeElement.appendChild(typeText);
    itemElement.appendChild(nameElement);
    itemElement.appendChild(typeElement);
    root.appendChild(itemElement);

    // Save the updated XML back to the file
    if (file.open(QIODevice::WriteOnly)) {
        QTextStream stream(&file);
        doc.save(stream, 4);
        file.close();
    }
}

bool MyStoreApp::itemExists(QList<MyItem> &itemList, const MyItem &newItem) {

    // Check for duplicates
    for (const auto &existingItem: itemList) {
        if (existingItem.name == newItem.name && existingItem.type == newItem.type) {
            // Duplicate item found
            return true;
        }
    }
    return false;
}

bool MyStoreApp::itemExists(QList<MyItem> &itemList, QString &name, QString &type) {
    // Check for duplicates

    for (const auto &existingItem: itemList) {

        if (existingItem.name == name && existingItem.type == type) {
            // Item exists
            return true;
        }
    }
    return false;
}


MyStoreApp::MyStoreApp(QWidget *parent) : QMainWindow(parent) {

    // Set Window Title + size
    setWindowTitle("My Store Management App");
    resize(1024, 768);

    // Center the MyStoreApp window
    if (const QScreen *screen = QGuiApplication::primaryScreen()) {
        const QRect availableGeometry = screen->availableGeometry();
        const int x = (availableGeometry.width() - width()) / 2;
        const int y = (availableGeometry.height() - height()) / 2;
        move(x, y);
    }

    // Load any existing items - will also save to this file for data persistence between application starts
    loadMyItems();

    //Load any existing transactions - will also save to this file for data persistence between application starts
    loadMyTransactions();

    // Create menu items
    QMenu *fileMenu = menuBar()->addMenu(tr("&File"));
    QMenu *itemMenu = menuBar()->addMenu(tr("&Admin"));
    QMenu *shopMenu = menuBar()->addMenu(tr("&Shop"));

    // Actions---------------------------------------------------------------------------------------------------------
    // Create Actions for Menu
    //Exit
    QAction *exitAction = new QAction(tr("&Exit"), this);
    fileMenu->addAction(exitAction);

    //List all shop items
    QAction *listItemsAction = new QAction(tr("&Admin-ListItems"), this);
    itemMenu->addAction(listItemsAction);

    //Admin -add an item
    QAction *addItemAction = new QAction(tr("&Admin-AddItem"), this);
    itemMenu->addAction(addItemAction);

    //User - shop and add a transaction/order
    QAction *addTransactionAction = new QAction(tr("Add Transaction"), this);
    shopMenu->addAction(addTransactionAction);

    // Signals and slots------------------------------------------------------------------------------------------------
    // Connect Actions to Slots
    connect(exitAction, &QAction::triggered, this, &QApplication::quit);

    // Connect Actions to Slots - AddMyItemDialog
    connect(addItemAction, &QAction::triggered, this, [=]() {
        AddMyItemDialog dialog(this);
        if (dialog.exec() == QDialog::Accepted) {

            // if the entry is accepted then save it
            QString itemName = dialog.getItemName();
            QString itemType = dialog.getItemType();
            if (itemType == "Book") {
                MyItem newItem = MyItem::createBook(itemName);
                addNewItem(newItem);

            } else if (itemType == "Magazine") {
                MyItem newItem = MyItem::createMagazine(itemName);
                addNewItem(newItem);
            }
        }
    });

    connect(listItemsAction, &QAction::triggered, this, [=]() {
        MyItemListDialog dialog(itemList, this);
        dialog.exec();
    });

    connect(addTransactionAction, &QAction::triggered, this, &MyStoreApp::showTransactionFormDialog);
}

void MyStoreApp::refreshMyTransactionsTreeView() {
    qDebug() << "Refreshing...";
    loadMyTransactions();
}

//Load the stock items
void MyStoreApp::loadMyItems() {

    QString appDir = QCoreApplication::applicationDirPath();
    QFile file(appDir + "/../MyItems.xml");

    if (file.open(QIODevice::ReadOnly)) {
        QDomDocument doc;
        if (doc.setContent(&file)) {
            QDomElement root = doc.documentElement();
            QDomNodeList items = root.elementsByTagName("item");

            for (int i = 0; i < items.count(); ++i) {
                QDomNode itemNode = items.at(i);
                QDomElement itemElem = itemNode.toElement();

                QString name = itemElem.elementsByTagName("name").at(0).toElement().text();
                QString type = itemElem.elementsByTagName("type").at(0).toElement().text();

                MyItem newItem = (type == "Book") ? MyItem::createBook(name) : MyItem::createMagazine(name);
                itemList.append(newItem);
            }
        }
        file.close();
    }
}

// Load all historical transactions - does send on load but could easily be switched off to only send new transactions
void MyStoreApp::loadMyTransactions() {

    int errors = 0;

    QString appDir = QCoreApplication::applicationDirPath();
    QFile file(appDir + "/../MyTransactions.xml");

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QDomDocument doc;
    if (!doc.setContent(&file)) {
        return;
    }

    QDomElement root = doc.documentElement();
    QDomNodeList transactionNodes = root.elementsByTagName("transaction");

    // for each transaction...
    QMap<QString, QList<MyTransaction>> transactionMap;

    for (int i = 0; i < transactionNodes.count(); ++i) {

        QDomNode transactionNode = transactionNodes.at(i);
        QDomElement transactionElement = transactionNode.toElement();

        QString date = transactionElement.attribute("date");
        QString user = transactionElement.attribute("user");

        // New Transaction object
        MyTransaction newTransaction(date, user);

        QDomNodeList lineItemNodes = transactionElement.elementsByTagName("lineitem");

        // for each line item ...
        for (int j = 0; j < lineItemNodes.count(); ++j) {

            QDomNode lineItemNode = lineItemNodes.at(j);
            QDomElement lineItemElement = lineItemNode.toElement();

            QString name = lineItemElement.attribute("name");
            QString type = lineItemElement.attribute("type");

            //check if type & name exists
            if (itemExists(itemList, name, type) == true) {

                int quantity = lineItemElement.attribute("quantity").toInt();

                MyTransactionLineItem myTransactionLineItem(name, type, quantity);

                // Add the line item to your Transaction object or data structure
                newTransaction.addLineItem(myTransactionLineItem);
            } else {
                errors++;
                qDebug() << "Stock item ( " << name << " & " << type
                         << " ) does not exist and cannot be loaded - orphan item";
            }
        }

        // Add the populated Transaction object to your list of transactions
        transactionList.append(newTransaction);
        transactionMap[newTransaction.user].append(newTransaction);
        qDebug() << "Added Transaction";
    }
    file.close();
    if (errors == 0) {
        MyTransactionTreeViewWidget *transactionTreeViewWidget = new MyTransactionTreeViewWidget();

        // Populate the tree view based on the XML file read
        transactionTreeViewWidget->populateTreeView(transactionMap);

        // Set this as the central widget
        setCentralWidget(transactionTreeViewWidget);

        //========================================
        // Initialize UDP socket and send the data
        sendUDP();

    } else {
        // If an item exists in the transaction xml but is not a stock item...
        QMessageBox::warning(this, "Error loading Transactions",
                             "An item could not be loaded, please fix the Transactions data and try again");
    }

}

void MyStoreApp::sendUDP() const {

    QString appDir = QCoreApplication::applicationDirPath();
    QFile file(appDir + "/../MyTransactions.xml");

    // Read the xml transactions file
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    QByteArray xmlData = file.readAll();

    // Set up UDP IP, port and sender properties
    QUdpSocket udpSocket;
    QByteArray transactionData;

    QHostAddress destAddress = QHostAddress("127.0.0.1");
    quint16 destPort = 49153;
    udpSocket.writeDatagram(xmlData, destAddress, destPort);

    qDebug() << "UDP message sent OK";
    file.close();
}

void MyStoreApp::showTransactionFormDialog() {

    MyTransactionFormDialog *transactionFormDialog = new MyTransactionFormDialog(this, this->itemList);

    // signal and slot to allow for refresh
    connect(transactionFormDialog, &MyTransactionFormDialog::transactionAdded, this,
            &MyStoreApp::refreshMyTransactionsTreeView);

    transactionFormDialog->setAttribute(Qt::WA_DeleteOnClose);
    transactionFormDialog->exec();
}

// Helper function to add new item if it does not already exist - i.e. prevent collisions & show warning
bool MyStoreApp::addNewItem(const MyItem &newItem) {
    if (itemExists(itemList, newItem) == false) {
        itemList.append(newItem);
        appendItemToXML(newItem);  // save to xml
        return true;
    } else {
        QMessageBox::warning(this, "Duplicate Item", "An item with that name already exists.");
        return false;
    }
}

