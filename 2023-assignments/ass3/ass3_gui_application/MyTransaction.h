#ifndef ASS3_GUI_APPLICATION_MYTRANSACTION_H
#define ASS3_GUI_APPLICATION_MYTRANSACTION_H

#include <QString>
#include <QList>
#include "MyTransactionLineItem.h"

class MyTransaction {
public:
    MyTransaction(const QString &date, const QString &user)
            : date(date), user(user) {}

    void addLineItem(const MyTransactionLineItem &item) {
        lineItems.append(item);
    }

    QString date;
    QString user;
    QList<MyTransactionLineItem> lineItems;
};

#endif
