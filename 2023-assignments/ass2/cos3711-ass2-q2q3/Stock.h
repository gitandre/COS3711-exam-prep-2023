#ifndef COS3711_ASS2_Q2_STOCK_H
#define COS3711_ASS2_Q2_STOCK_H
#include <QString>

class Stock
{
protected:
    QString item;
    int quantity;

public:
    Stock() {}
    Stock(QString item, int quantity) : item(item), quantity(quantity) {}
    virtual ~Stock() {}

    virtual QString getItem() { return item; }
    virtual int getQuantity() { return quantity; }

    virtual void setItem(QString item) { item = item; }
    virtual void setQuantity(int qty) { quantity = qty; }

    virtual QString toString() = 0;
};
#endif
