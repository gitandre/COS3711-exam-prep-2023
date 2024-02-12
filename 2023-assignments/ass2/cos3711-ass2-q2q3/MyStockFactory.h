#ifndef COS3711_ASS2_Q2_MYSTOCKFACTORY_H
#define COS3711_ASS2_Q2_MYSTOCKFACTORY_H
#include <memory>
#include "Confectionary.h"
#include "ReadingMaterial.h"

class MyStockFactory
{
public:
    virtual ~MyStockFactory() {}
    virtual std::unique_ptr<Stock> create(QString type, QString name, int quantity, QString extra) = 0;
};
#endif
