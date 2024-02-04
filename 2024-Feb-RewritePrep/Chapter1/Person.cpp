//
// Created by User on 2/4/2024.
//
#include <iostream>
#include "Person.h"

Person::Person(int &val) : m_birthYear(val) {
    cout << "\nDefault constructor called" << endl;
    name = "-";
    age = 0;
    occupation = "-";
}

Person::Person(string n, int a, int &in_birthYear, string o) : m_birthYear(in_birthYear) {
    cout << "\nParameterized constructor called" << endl;
    name = n;
    age = a;
    occupation = o;
}

void Person::displayInfo() const {
    cout << "\ndisplayInfo()" << endl;
    cout << "Name: " << name << ", Age: " << age << ", Occupation: " << occupation << endl;
}

void Person::haveBirthday() {
    cout << "\nhaveBirthday()" << endl;
    int prev_age = age;
    age++;
    cout << "Happy birthday, you were " << prev_age << " but now you are " << age << endl;
}


