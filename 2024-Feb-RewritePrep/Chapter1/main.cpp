#include <iostream>
#include "Person.h"

using namespace std;

int main() {

    // We will create a logger here later using Singleton
    // todo


    // Print static explanation about a class
    cout << Person::PersonExplanation() << endl;

    // Instantiate Person Class Def
    // Very basic OOP example
    Person p1;
    p1.displayInfo();
    p1.haveBirthday();

    // Instantiate Person Class Params
    Person p2("Joe", 18, "Student");
    p2.displayInfo();
    p2.haveBirthday();

    // loop and create Persons
    cout << "loop and create Persons start---------------------------\n" << endl;
    for (int i = 0; i <= 3; i++) {
        Person p;
        cout << "---" << endl;
    } // these objects go out of scope on each loop by design
    cout << "loop and create Persons end---------------------------\n" << endl;

    cout << "\nFinal Person object count" << endl;
    cout << "Person Objects = " << Person::PersonObjectCount() << endl;

    return 0;
}
