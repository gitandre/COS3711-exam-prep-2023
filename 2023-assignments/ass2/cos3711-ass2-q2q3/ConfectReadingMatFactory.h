#ifndef COS3711_ASS2_Q2_CONFECTREADINGMATFACTORY_H
#define COS3711_ASS2_Q2_CONFECTREADINGMATFACTORY_H
#include "MyStockFactory.h"

class ConfectReadingMatFactory : public MyStockFactory
{
public:
    std::unique_ptr<Stock> create(QString type, QString name, int quantity, QString extra) override
    {
        if (type == "Confectionary") {
            return std::make_unique<Confectionary>(name, quantity, extra.toInt());
        }
        else if (type == "ReadingMaterial") {
            return std::make_unique<ReadingMaterial>(name, quantity, extra);
        }
        else {
            // Handle any unknown stock types in Factory
            throw std::runtime_error("Invalid stock item type.");
        }
    }
};
#endif
