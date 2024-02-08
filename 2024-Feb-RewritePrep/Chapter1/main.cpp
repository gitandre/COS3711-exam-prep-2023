#include <iostream>
#include "Person.h"

using namespace std;


int main() {


    // Instantiate Person Class Def
    Person p1;
    p1.displayInfo();
    p1.haveBirthday();

    // Instantiate Person Class Params
    Person p2("Joe", 18,"Student");
    p2.displayInfo();
    p2.haveBirthday();

    return 0;
}
