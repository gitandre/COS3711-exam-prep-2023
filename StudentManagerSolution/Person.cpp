//
// Created by User on 10/17/2023.
//

#include "Person.h"

int Person::getId() {
    return id;
}

QString Person::getName() {
    return name;
}

QString Person::getEmail() {
    return email;
}

void Person::setEmail(QString &p_email) {
    email = p_email;
}

void Person::setName(QString &p_name) {
    email = p_name;
}

void Person::setId(int p_id) {
    id = p_id;
}



