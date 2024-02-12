#include <QFormLayout>
#include <QPushButton>
#include <QDialogButtonBox>

#include "MyStockDialog.h"

MyStockDialog::MyStockDialog(QWidget *parent) :
        QDialog(parent),
        itemEdit(new QLineEdit(this)),
        quantitySpin(new QSpinBox(this)),
        extraEdit(new QLineEdit(this)),
        typeBox(new QComboBox(this))
{
    // Add a type selector widget
    typeBox->addItem("Confectionary");
    typeBox->addItem("ReadingMaterial");

    // Add layout for widgets
    QFormLayout* formLayout = new QFormLayout;
    formLayout->addRow("Type", typeBox);
    formLayout->addRow("Item", itemEdit);
    formLayout->addRow("Quantity", quantitySpin);
    formLayout->addRow("Extra (Weight/Frequency)", extraEdit);

    // Add buttons
    QDialogButtonBox* buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, this);
    connect(buttonBox, &QDialogButtonBox::accepted, this, &QDialog::accept);
    connect(buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);

    // Set layouts
    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout->addLayout(formLayout);
    mainLayout->addWidget(buttonBox);

    setLayout(mainLayout);
    setWindowTitle("Capture Stock Item - Select stock type");
}

Confectionary MyStockDialog::getConfectionary()
{
    return Confectionary(itemEdit->text(), quantitySpin->value(), extraEdit->text().toInt());
}

ReadingMaterial MyStockDialog::getReadingMaterial()
{
    return ReadingMaterial(itemEdit->text(), quantitySpin->value(), extraEdit->text());
}

QString MyStockDialog::getType()
{
    return typeBox->currentText();
}

QString MyStockDialog::getItem() {
    return itemEdit->text();
}

int MyStockDialog::getQuantity() {
    return quantitySpin->value();
}

QString MyStockDialog::getExtra() {
    return extraEdit->text();
}
