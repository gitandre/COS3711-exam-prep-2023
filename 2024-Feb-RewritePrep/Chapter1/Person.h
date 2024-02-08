//
// Created by User on 2/4/2024.
//

#ifndef CHAPTER1_PERSON_H
#define CHAPTER1_PERSON_H

#include <string>

using namespace std;

class Person {
public:

    // Constructors
    Person();
    Person(string n, int a, string o);
    ~Person();


    // Setters
    void SetName(string n);
    void SetAge(int a);
    void SetOccupation(string o);

    //Getters

    // Functions
    void displayInfo() const;
    void haveBirthday();

private:

    // private members
    string m_name;
    int m_age;
    string m_occupation;
};


#endif //CHAPTER1_PERSON_H
