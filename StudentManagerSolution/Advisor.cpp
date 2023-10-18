//
// Created by User on 10/17/2023.
//

#include "Advisor.h"
#include "QDebug"

Advisor::~Advisor() {
    qInfo() << "Advisor " + this->getName() + " destructed";
}
