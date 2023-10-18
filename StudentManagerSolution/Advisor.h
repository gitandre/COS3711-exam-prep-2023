//
// Created by User on 10/17/2023.
//

#ifndef AdvisorMANAGERSOLUTION_ADVISOR_H
#define AdvisorMANAGERSOLUTION_ADVISOR_H

#include "Person.h"
#include "QDebug"

class Advisor : public Person {
Q_OBJECT

public:
    Advisor() {
        qInfo() << "Advisor constructed with default";
    }

    explicit Advisor(QString name, QString email, int id = -1) : Person(id, name, email) {
        qInfo() << "Advisor " << this->getName() << " constructed with params";
    }

    SolutionObjectType getObjectType() override {
        return objectType;
    }

    ~Advisor() override;

private:
    SolutionObjectType objectType = SolutionObjectType::ADVISOR;
};

#endif //AdvisorMANAGERSOLUTION_ADVISOR_H
