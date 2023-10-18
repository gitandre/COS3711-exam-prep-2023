//
// Created by User on 10/17/2023.
//

#include "Student.h"
#include "QDebug"

Student::~Student() {
    qInfo() << "Student " + this->getName() + " destructed";
}
