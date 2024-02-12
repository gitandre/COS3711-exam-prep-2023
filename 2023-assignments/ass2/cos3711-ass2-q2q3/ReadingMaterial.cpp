#include "ReadingMaterial.h"

// Get the ReadingMaterial item properties as a single string
QString ReadingMaterial::toString() {
    return "Reading Material Item: " + item + ", Quantity: " + QString::number(quantity) + ", Frequency: " + frequency;
}