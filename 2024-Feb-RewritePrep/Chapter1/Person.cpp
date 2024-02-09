//
// Created by User on 2/4/2024.
//
#include <iostream>
#include "Person.h"
#include "SingletonLogger/SingletonLogger.h"

int Person::s_count = 0;


Person::Person() {

    string x = "foo";
    s_logger().log(x);

    m_name = "";
    m_age = -1;
    m_occupation = "";

    s_count++;

//    s_logger.log("Person Objects = " + to_string(Person::PersonObjectCount()));

    // Prints out static Class Explanation
    // cout << Person::PersonExplanation() << endl;
}

Person::Person(string n, int a, string o) : m_name(n), m_age(a), m_occupation(o) {

//    s_logger.log(
//            "Person::Person(string n, int a, string) Parameterized Person Constructed with " + n + " " + to_string(a) +
//            " " + o);

    s_count++;
//    s_logger.log("Person Objects = " + to_string(Person::PersonObjectCount()));
    // Prints out static Class Explanation
    // cout << Person::PersonExplanation() << endl;
}

void Person::displayInfo() const {

//    s_logger.log(".displayInfo()");
//    s_logger.log("Name: " + m_name + ", Age: " + to_string(m_age) + ", Occupation: " + m_occupation);

}

void Person::haveBirthday() {

//    s_logger.log(".haveBirthday()");
    if (m_age != -1) {

        int prev_age = m_age;
        m_age++;

//        s_logger.log("Happy birthday, you were " + to_string(prev_age) + " but now you are " + to_string(m_age));
    } else {
//        s_logger.log("Please set the age, cannot increment -1");
    }
}

Person::~Person() {
//    s_logger.log(".Destructing Person started...");
    displayInfo();
//    s_logger.log(".Destructing Person ending...");

    s_count--;
//    s_logger.log("Person Objects = " + to_string(Person::PersonObjectCount()));


    SingletonLogger::getInstance().getLogs();
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

//    s_logger.log( to_string(s_count) + " objects in memory");

    return s_count;
}

Person::Person(string n, int a, string o, Person *pPtr) {

    m_name = n;
    m_age = a;
    m_occupation = o;
    m_personPtr = pPtr;
}




