//
// Created by User on 2/4/2024.
//
#include <iostream>
#include "Person.h"

int Person::s_count = 0;

Person::Person() {
    cout << this << " Person::Person()" << endl;
    m_name = "";
    m_age = -1;
    m_occupation = "";

    s_count++;
    cout << "Person Objects = " << Person::PersonObjectCount() << endl;
    // Prints out static Class Explanation
    // cout << Person::PersonExplanation() << endl;
}

Person::Person(string n, int a, string o) : m_name(n), m_age(a), m_occupation(o) {

    cout << this << "Person::Person(string n, int a, string) Paramterised Person Constructed with " << n << ", " << a
         << " and " << o << endl;
    s_count++;
    cout << "Person Objects = " << Person::PersonObjectCount() << endl;
    // Prints out static Class Explanation
    // cout << Person::PersonExplanation() << endl;
}

void Person::displayInfo() const {

    cout << this << ".displayInfo()" << endl;
    cout << "Name: " << m_name << ", Age: " << m_age << ", Occupation: " << m_occupation << endl;

}

void Person::haveBirthday() {

    cout << this << ".haveBirthday()" << endl;
    if (m_age != -1) {

        int prev_age = m_age;
        m_age++;

        cout << "Happy birthday, you were " << prev_age << " but now you are " << m_age << endl;
    } else {
        cout << "Please set the age, cannot increment -1" << endl;
    }
}

Person::~Person() {
    cout << this << ".Destructing Person started..." << endl;
    displayInfo();
    cout << this << ".Destructing Person ending..." << endl;

    s_count--;
    cout << "Person Objects = " << Person::PersonObjectCount() << endl;
}

bool Person::savePersonToFile() {
    return false;
}

bool Person::readPersonFromFile() {
    return false;
}

void Person::SetName(string n) {
    m_name = n;
}

void Person::SetAge(int a) {
    m_age = a;
}

void Person::SetOccupation(string o) {

    m_occupation = o;
}

// define, set and return a static member
const string &Person::PersonExplanation() {

    static const string PERSON_EXAMPLE = R"(
Usage:
    // Very basic OOP example
    Person p1;
    p1.displayInfo();
    p1.haveBirthday();

    // Instantiate Person Class Params
    Person p2("Joe", 18,"Student");
    p2.displayInfo();
    p2.haveBirthday();
)";

    return PERSON_EXAMPLE;
}

int Person::PersonObjectCount() {

    cout << s_count << " objects in memory" << endl;

    return s_count;
}




