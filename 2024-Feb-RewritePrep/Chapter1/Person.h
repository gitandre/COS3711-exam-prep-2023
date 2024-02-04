//
// Created by User on 2/4/2024.
//

#ifndef CHAPTER1_PERSON_H
#define CHAPTER1_PERSON_H

#include <string>

using namespace std;

class Person {
public:
    string name;
    int age;
    int &m_birthYear;
    string occupation;

    explicit Person(int &val);

    Person(string n, int a, int &val, string o);

    void displayInfo() const;

    void haveBirthday();
};


#endif //CHAPTER1_PERSON_H
