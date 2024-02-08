//
// Created by User on 2/4/2024.
//
#include <iostream>
#include "Person.h"


Person::Person() {
    m_name = "";
    m_age = -1;
    m_occupation = "";
}

Person::Person(string n, int a, string o) : m_name(n), m_age(a), m_occupation(o) {

    cout << "Paramterised Person Constructed with " << n << ", " << a << " and " << o << endl;
}

void Person::displayInfo() const {

    cout << "\ndisplayInfo()" << endl;
    cout << "Name: " << m_name << ", Age: " << m_age << ", Occupation: " << m_occupation << endl;
}

void Person::haveBirthday() {

    cout << "\nhaveBirthday()" << endl;
    if (m_age != -1) {

        int prev_age = m_age;
        m_age++;

        cout << "Happy birthday, you were " << prev_age << " but now you are " << m_age << endl;
    } else {
        cout << "Please set the age, cannot increment -1" << endl;
    }
}

Person::~Person() {
    cout << "Destructing Person started..." << endl;
    displayInfo();
    cout << "Destructing Person ending..." << endl;
}



