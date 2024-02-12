//
// Created by andre on 2023/07/09.
//

#ifndef COS3711_ASS2_Q2_CONFECTIONARY_H
#define COS3711_ASS2_Q2_CONFECTIONARY_H
#include "Stock.h"

class Confectionary : public Stock
{
private:
    int weight;

public:
    Confectionary() : Stock() {}
    Confectionary(QString item, int qty, int weight) : Stock(item, qty), weight(weight) {}
    ~Confectionary() {} // destructor

    int getWeight() { return weight; }
    void setWeight(int weight) { weight = weight; }

    QString toString() override;
};

#endif
