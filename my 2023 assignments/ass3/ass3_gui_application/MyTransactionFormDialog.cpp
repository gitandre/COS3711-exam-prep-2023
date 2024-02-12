#include "MyTransactionFormDialog.h"
#include "MyTransactionLineItem.h"
#include <QVariant>
#include <QFile>
#include <QXmlStreamWriter>
#include <QCoreApplication>
#include <QDateTime>
#include <QMessageBox>
#include <QDomDocument>

MyTransactionFormDialog::MyTransactionFormDialog(QWidget *parent, QList<MyItem> passedInItem) : QDialog(parent) {

    setWindowTitle("Add Transaction");
    resize(500, 800);

    myItems = passedInItem;


    // Customer Username
    customerUsername = new QLineEdit("Enter your username", this);

    // Item Type Dropdown
    itemTypeComboBox = new QComboBox(this);
    itemTypeComboBox->addItem("Book");
    itemTypeComboBox->addItem("Magazine");

    // Item List Dropdown
    itemListComboBox = new QComboBox(this);

    //Quantity
    quantitySpinBox = new QSpinBox(this);
    quantitySpinBox->setMinimum(0);
    quantitySpinBox->setMaximum(10000);

    //Order Button
    addToOrderButton = new QPushButton("Add To or Update Order", this);

    // Show Added Items List
    addedItemsQListWidget = new QListWidget(this);

    // Save and Close Button - refreshes parent and sends UDP signal
    saveAndCloseButton = new QPushButton("Save and Close", this);

    // Layouts
    QFormLayout * formLayout = new QFormLayout;
    formLayout->addRow("Customer Username:", customerUsername);
    formLayout->addRow("Item Type:", itemTypeComboBox);
    formLayout->addRow("Item:", itemListComboBox);
    formLayout->addRow("Quantity:", quantitySpinBox);

    QVBoxLayout * mainLayout = new QVBoxLayout(this);
    mainLayout->addLayout(formLayout);
    mainLayout->addWidget(addToOrderButton);
    mainLayout->addWidget(addedItemsQListWidget);
    mainLayout->addWidget(saveAndCloseButton);

    // Signals and Slots ----------------------------------------------------------------------------------------------
    connect(itemTypeComboBox, &QComboBox::currentTextChanged,
            this, &MyTransactionFormDialog::onItemTypeChanged);

    connect(itemListComboBox, &QComboBox::currentTextChanged,
            this, &MyTransactionFormDialog::onItemSelected);

    connect(addToOrderButton, &QPushButton::clicked,
            this, &MyTransactionFormDialog::onAddToOrderClicked);

    connect(saveAndCloseButton, &QPushButton::clicked, this,
            &MyTransactionFormDialog::onSaveAndCloseClicked);

    // Load the stick items
    for (const auto &item: myItems) {
        if (item.type == itemTypeComboBox->currentText()) {
            itemListComboBox->addItem(item.name);
        }
    }
}

// When the item type is changed update the stock items dropdown list
void MyTransactionFormDialog::onItemTypeChanged(const QString &selectedType) {
    itemListComboBox->clear();
    for (const auto &item: myItems) {
        if (item.type == selectedType) {
            itemListComboBox->addItem(item.name);
        }
    }
}

// When an item is selected set a global item selected index
void MyTransactionFormDialog::onItemSelected(const QString &selectedItemString) {

    int i = 0;
    for (const MyItem &item: myItems) {
        if (item.type == itemTypeComboBox->currentText() && itemListComboBox->currentText() == selectedItemString) {
            selectedItemIndex = reinterpret_cast<long long int>(reinterpret_cast<int *>(i));
            return;
        }
        i++;
    }
}

// Add the item to the order/transaction
void MyTransactionFormDialog::onAddToOrderClicked() {

    // handle bad username
    if (customerUsername->text() != "Enter your username") {

        // handle zero quantity
        if (quantitySpinBox->value() > 0) {
            bool itemExists = false;

            // Create a MyTransactionLineItem
            MyTransactionLineItem myTransactionLineItem(
                    myItems[selectedItemIndex].name,
                    myItems[selectedItemIndex].type,
                    quantitySpinBox->value()
            );

            // Loop through the existing items to see if this one already exists
            for (int i = 0; i < addedItemsQListWidget->count(); ++i) {
                QListWidgetItem *existingItem = addedItemsQListWidget->item(i);
                QVariant variant = existingItem->data(Qt::UserRole);
                MyTransactionLineItem existingLineItem = variant.value<MyTransactionLineItem>();

                if (existingLineItem.name == myTransactionLineItem.name &&
                    existingLineItem.type == myTransactionLineItem.type) {
                    // Item exists, update quantity
                    existingLineItem.quantity = myTransactionLineItem.quantity;
                    existingItem->setData(Qt::UserRole, QVariant::fromValue(existingLineItem));
                    existingItem->setText(existingLineItem.name + " | " + existingLineItem.type + " | " +
                                          QString::number(existingLineItem.quantity));
                    itemExists = true;
                    break;
                }
            }

            // If item did not already exist, add as new
            if (!itemExists) {
                QListWidgetItem *newItem = new QListWidgetItem;

                // Convert the MyTransactionLineItem object to a QVariant
                QVariant variant = QVariant::fromValue(myTransactionLineItem);

                // Associate QVariant with the QListWidgetItem
                newItem->setData(Qt::UserRole, variant);

                // Set a display text for the QListWidgetItem
                newItem->setText(myTransactionLineItem.name + " | " + myTransactionLineItem.type + " | " +
                                 QString::number(myTransactionLineItem.quantity));

                // Add the item to the QListWidget
                addedItemsQListWidget->addItem(newItem);
            }

            // Reset the quantity spin box
            quantitySpinBox->setValue(0);

            // Show a success message
            QMessageBox::information(this, "Success", "Item added OK :)");
        } else {
            // If the user does not enter a valid username...
            QMessageBox::warning(this, "Error", "Please enter a quantity greater than zero");
        }

    } else {

        // If the user does not enter a valid username...
        QMessageBox::warning(this, "Error", "Please enter a valid username");
    }
}


void MyTransactionFormDialog::onSaveAndCloseClicked() {

    //Loop through all items
    QList<MyTransactionLineItem> transactionLineItems;
    for (int i = 0; i < addedItemsQListWidget->count(); ++i) {
        QListWidgetItem *listItem = addedItemsQListWidget->item(i);

        //Retrieve the data and cast it back
        QVariant variant = listItem->data(Qt::UserRole);
        MyTransactionLineItem lineItem = variant.value<MyTransactionLineItem>();
        transactionLineItems.append(lineItem);
    }

    QString appDir = QCoreApplication::applicationDirPath();
    QFile file(appDir + "/../MyTransactions.xml");

    // Load and add new transaction to MyTransactions.xml
    QDomDocument doc;

    if (file.open(QIODevice::ReadOnly)) {
        if (!doc.setContent(&file)) {
            file.close();
            return;
        }
        file.close();
    }

    QDomElement root = doc.documentElement();
    if (root.isNull()) {
        root = doc.createElement("Transactions");
        doc.appendChild(root);
    }

    QDomElement newTransactionElem = doc.createElement("transaction");
    newTransactionElem.setAttribute("date", QDateTime::currentDateTime().toString(Qt::ISODate));
    newTransactionElem.setAttribute("user", customerUsername->text());

    for (const MyTransactionLineItem &lineItem: transactionLineItems) {
        QDomElement lineItemElem = doc.createElement("lineitem");
        lineItemElem.setAttribute("name", lineItem.name);
        lineItemElem.setAttribute("type", lineItem.type);
        lineItemElem.setAttribute("quantity", QString::number(lineItem.quantity));
        newTransactionElem.appendChild(lineItemElem);
    }

    root.appendChild(newTransactionElem);

    if (file.open(QIODevice::WriteOnly)) {
        QTextStream stream(&file);
        doc.save(stream, 4);
        file.close();
    }

    // refresh the transaction tree view on MyStoreApp
    emit transactionAdded();

    QMessageBox::information(this, "Success", "Transaction Saved OK :)");
    this->close();
}
