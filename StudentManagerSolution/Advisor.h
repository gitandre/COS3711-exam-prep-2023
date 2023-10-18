//
// Created by User on 10/17/2023.
//

#ifndef AdvisorMANAGERSOLUTION_ADVISOR_H
#define AdvisorMANAGERSOLUTION_ADVISOR_H

#include "Person.h"

class Advisor : public Person {
Q_OBJECT

public:
    Advisor() = default;

    explicit Advisor(QString name = "", QString email = "", int id = -1) : Person(id, name, email) {}

    SolutionObjectType getObjectType() override {
        return objectType;
    }

    ~Advisor() override;

private:
    SolutionObjectType objectType = SolutionObjectType::ADVISOR;
};

#endif //AdvisorMANAGERSOLUTION_ADVISOR_H
