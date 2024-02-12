#include "AddMyItemDialog.h"
#include <QPushButton>
#include <QFormLayout>
#include <QDialogButtonBox>

AddMyItemDialog::AddMyItemDialog(QWidget *parent) : QDialog(parent) {
    setWindowTitle("Add Item");

    itemNameLineEdit = new QLineEdit(this);
    itemTypeComboBox = new QComboBox(this);
    itemTypeComboBox->addItem("Book");
    itemTypeComboBox->addItem("Magazine");

    QFormLayout *formLayout = new QFormLayout;
    formLayout->addRow("Item Name:", itemNameLineEdit);
    formLayout->addRow("Item Type:", itemTypeComboBox);

    QDialogButtonBox *buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, this);
    connect(buttonBox, &QDialogButtonBox::accepted, this, &QDialog::accept);
    connect(buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addLayout(formLayout);
    mainLayout->addWidget(buttonBox);
}

QString AddMyItemDialog::getItemName() const {
    return itemNameLineEdit->text();
}

QString AddMyItemDialog::getItemType() const {
    return itemTypeComboBox->currentText();
}
