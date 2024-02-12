#ifndef MYTRANSACTIONTREEVIEWWIDGET_H
#define MYTRANSACTIONTREEVIEWWIDGET_H

#include <QWidget>
#include <QTreeView>
#include <QStandardItemModel>
#include <QVBoxLayout>
#include "MyTransaction.h"

class MyTransactionTreeViewWidget : public QWidget {
Q_OBJECT

public:
    MyTransactionTreeViewWidget(QWidget *parent = nullptr);

    // Method to populate the tree view
    void populateTreeView(const QMap<QString, QList<MyTransaction>> &userTransactions);

private:
    QTreeView *treeView;
    QStandardItemModel *model;
};

#endif
