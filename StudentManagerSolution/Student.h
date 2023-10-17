//
// Created by User on 10/17/2023.
//

#ifndef STUDENTMANAGERSOLUTION_STUDENT_H
#define STUDENTMANAGERSOLUTION_STUDENT_H

#include <utility>

#include "Person.h"
#include "SolutionObjectType.h"

class Student: public Person {
public:
    Student()= default;
    explicit Student(QString name="", QString email="",int id=-1): Person(id, name, email) {}

    SolutionObjectType getObjectType() override {
        return objectType;
    }
    ~Student() override;

private:
    SolutionObjectType objectType = SolutionObjectType::STUDENT;
};


#endif //STUDENTMANAGERSOLUTION_STUDENT_H
