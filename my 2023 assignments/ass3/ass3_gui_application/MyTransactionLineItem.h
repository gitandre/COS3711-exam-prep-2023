#ifndef ASS3_GUI_APPLICATION_MYTRANSACTIONLINEITEM_H
#define ASS3_GUI_APPLICATION_MYTRANSACTIONLINEITEM_H

#include <QString>
#include <QMetaType>

class MyTransactionLineItem {
public:
    MyTransactionLineItem() : name(""), type(""), quantity(0) {};

    MyTransactionLineItem(const QString &name, const QString &type, int quantity)
            : name(name), type(type), quantity(quantity) {}

    QString name;
    QString type;
    int quantity;
};

Q_DECLARE_METATYPE(MyTransactionLineItem)

#endif
