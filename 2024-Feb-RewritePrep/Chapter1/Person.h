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
    Person(string n, int a, string o, Person* pPtr);
    ~Person();


    // Setters
    void SetName(string n);
    void SetAge(int a);
    void SetOccupation(string o);

    //Getters

    // Functions
    void displayInfo() const;
    void haveBirthday();

    bool savePersonToFile();
    bool readPersonFromFile();

    // static function to return a static member
    static const string& PersonExplanation();

    static int PersonObjectCount();

private:

    // private members
    string m_name;
    int m_age;
    string m_occupation;

    static int s_count;

    Person* m_personPtr = nullptr;
};


#endif //CHAPTER1_PERSON_H
