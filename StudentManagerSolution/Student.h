//
// Created by User on 10/17/2023.
//

#ifndef STUDENTMANAGERSOLUTION_STUDENT_H
#define STUDENTMANAGERSOLUTION_STUDENT_H

#include <utility>

#include "Person.h"
#include "SolutionObjectType.h"
#include "QDebug"

class Student : public Person {
Q_OBJECT

public:
    Student() {
        qInfo() << "Student constructed with default";
    }

    explicit Student(QString name, QString email, int id=-1 ) : Person(id, name, email) {
        qInfo() << "Student " << this->getName() << " constructed with params";
    }

    SolutionObjectType getObjectType() override {
        return objectType;
    }

    ~Student() override;

private:
    SolutionObjectType objectType = SolutionObjectType::STUDENT;
};


#endif //STUDENTMANAGERSOLUTION_STUDENT_H
