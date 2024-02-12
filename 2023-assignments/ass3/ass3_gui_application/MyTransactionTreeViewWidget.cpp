#include "MyTransactionTreeViewWidget.h"
#include "MyTransaction.h"

// Constructor for MyTransactionTreeViewWidget
MyTransactionTreeViewWidget::MyTransactionTreeViewWidget(QWidget *parent) : QWidget(parent) {
    model = new QStandardItemModel();
    treeView = new QTreeView(this);

    QVBoxLayout * layout = new QVBoxLayout(this);
    layout->addWidget(treeView);
    setLayout(layout);

    treeView->setModel(model);
    treeView->expandAll();
}

// Populate the tree view with the transaction data
void MyTransactionTreeViewWidget::populateTreeView(const QMap<QString, QList<MyTransaction>> &userTransactions) {
    model->clear();

    QMapIterator<QString, QList<MyTransaction>> i(userTransactions);
    while (i.hasNext()) {
        i.next();
        QStandardItem *userItem = new QStandardItem(i.key());
        model->appendRow(userItem);
        model->setHorizontalHeaderLabels(
                QStringList() << "User     Date/Time     Transaction Data (Name, Type, Quantity)");

        for (const MyTransaction &transaction: i.value()) {
            QStandardItem *transactionItem = new QStandardItem(transaction.date);
            userItem->appendRow(transactionItem);

            for (const MyTransactionLineItem &lineItem: transaction.lineItems) {
                QString lineItemText = QString("%1, %2, %3").arg(lineItem.name, lineItem.type,
                                                                 QString::number(lineItem.quantity));
                QStandardItem *lineItemStandardItem = new QStandardItem(lineItemText);
                transactionItem->appendRow(lineItemStandardItem);
            }
        }
    }

    //Set tree view properties and solumn width
    treeView->setModel(model);
    treeView->setColumnWidth(0, 50);
    treeView->setColumnWidth(1, 100);
    treeView->setColumnWidth(2, 200);
    treeView->setColumnWidth(3, 200);
    treeView->expandAll();
}
