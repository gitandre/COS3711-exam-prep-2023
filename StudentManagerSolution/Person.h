//
// Created by User on 10/17/2023.
//

#ifndef STUDENTMANAGERSOLUTION_PERSON_H
#define STUDENTMANAGERSOLUTION_PERSON_H


#include <QString>
#include "SolutionObjectType.h"
#include <QObject>
#include <QDebug>

class Person: public QObject {
    Q_OBJECT
public:
    Person(){
        qInfo() << "Person constructed using default";
    }
    Person(int p_id, QString p_name, QString p_email): id(p_id), name(p_name), email(p_email){
        qInfo() << "Person constructed with params";
    }

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
