#ifndef ASS3_GUI_APPLICATION_MYTRANSACTIONFORMDIALOG_H
#define ASS3_GUI_APPLICATION_MYTRANSACTIONFORMDIALOG_H

#include <QDialog>
#include <QFormLayout>
#include <QLineEdit>
#include <QComboBox>
#include <QSpinBox>
#include <QPushButton>
#include <QListWidget>
#include <QVBoxLayout>
#include "MyItem.h"

class MyTransactionFormDialog : public QDialog {
Q_OBJECT
public:
    MyTransactionFormDialog(QWidget *parent = nullptr, QList<MyItem> myItems = QList<MyItem>());

    void updateItemList(const QString &selectedType);

private slots:

    void onItemTypeChanged(const QString &selectedType);

    void onItemSelected(const QString &selectedType);

    void onAddToOrderClicked();

private:
    QLineEdit *customerUsername;
    QComboBox *itemTypeComboBox;
    QComboBox *itemListComboBox;
    QSpinBox *quantitySpinBox;
    QList<MyItem> myItems;
    long long int selectedItemIndex;
    QPushButton *addToOrderButton;
    QPushButton *saveAndCloseButton;

    QListWidget *addedItemsQListWidget;

    void onSaveAndCloseClicked();

signals:

    void transactionAdded();
};

#endif
