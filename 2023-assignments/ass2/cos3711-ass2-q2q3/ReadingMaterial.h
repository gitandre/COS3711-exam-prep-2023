#ifndef COS3711_ASS2_Q2_READINGMATERIAL_H
#define COS3711_ASS2_Q2_READINGMATERIAL_H
#include "Stock.h"

class ReadingMaterial : public Stock
{
private:
    QString frequency;

public:
    ReadingMaterial() : Stock() {}
    ReadingMaterial(QString i, int q, QString f) : Stock(i, q), frequency(f) {}
    ~ReadingMaterial() {}

    QString getFrequency() { return frequency; }
    void setFrequency(QString freq) { frequency = freq; }

    QString toString() override;
};
#endif