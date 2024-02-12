#ifndef STOREAPP_H
#define STOREAPP_H

#include <QMainWindow>
#include "MyItem.h"
#include "MyTransaction.h"

class MyStoreApp : public QMainWindow {
Q_OBJECT
public:
    explicit MyStoreApp(QWidget *parent = nullptr);

private:
    QList<MyItem> itemList;

private:
    QList<MyTransaction> transactionList; // this is the "backup" in memory being hard disk
    void appendItemToXML(const MyItem &newItem);

    bool itemExists(QList<MyItem> &itemList, const MyItem &newItem);

    bool addNewItem(const MyItem &newItem);

public slots:

    void loadMyTransactions();

    void loadMyItems();

private slots:

    void showTransactionFormDialog();

    bool itemExists(QList<MyItem> &itemList, QString &name, QString &type);

    void refreshMyTransactionsTreeView();

    void sendUDP() const;
};

#endif
