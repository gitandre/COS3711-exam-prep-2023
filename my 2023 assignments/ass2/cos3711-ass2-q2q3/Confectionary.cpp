#include "Confectionary.h"

// Get the Confectionary item properties as a single string
QString Confectionary::toString() {
    return "Confectionary Item: " + item + ", Quantity: " + QString::number(quantity) + ", Weight: " + QString::number(weight);
}