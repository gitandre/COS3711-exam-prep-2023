#ifndef ADDITEMDIALOG_H
#define ADDITEMDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QComboBox>

class AddMyItemDialog : public QDialog {
Q_OBJECT
public:
    explicit AddMyItemDialog(QWidget *parent = nullptr);
    QString getItemName() const;
    QString getItemType() const;

private:
    QLineEdit *itemNameLineEdit;
    QComboBox *itemTypeComboBox;
};

#endif
