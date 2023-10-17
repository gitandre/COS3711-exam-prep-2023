//
// Created by User on 10/17/2023.
//

#ifndef STUDENTMANAGERSOLUTION_PERSON_H
#define STUDENTMANAGERSOLUTION_PERSON_H


#include <QString>
#include "SolutionObjectType.h"

class Person {
public:
    Person()= default;
    Person(int p_id, QString p_name, QString p_email): id(p_id), name(p_name), email(p_email){}

    int getId();
    void setId(int id);

    QString getName();
    void setName(QString &name);

    QString getEmail();
    void setEmail(QString &email);

    virtual SolutionObjectType getObjectType() = 0;

    virtual ~Person() {}
private:
    int id{};
    QString name;
    QString email;
};


#endif //STUDENTMANAGERSOLUTION_PERSON_H
