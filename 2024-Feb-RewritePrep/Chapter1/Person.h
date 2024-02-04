//
// Created by User on 2/4/2024.
//

#ifndef CHAPTER1_PERSON_H
#define CHAPTER1_PERSON_H

#include <string>
using namespace std;

class Person{
public:
    string name;
    int age;
    string occupation;

    Person();
    Person(string n, int a, string o);

    void displayInfo() const;
    void haveBirthday();
};




#endif //CHAPTER1_PERSON_H
