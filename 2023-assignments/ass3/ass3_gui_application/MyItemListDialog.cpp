#include "MyItemListDialog.h"
#include <QVBoxLayout>

MyItemListDialog::MyItemListDialog(const QList<MyItem> &items, QWidget *parent) : QDialog(parent) {
    listWidget = new QListWidget(this);
    setWindowTitle("My Items List");
    resize(500, 400);

    for (const auto &item : items) {
        listWidget->addItem(item.name + " (" + item.type + ")");
    }

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(listWidget);
}
