#include <iostream>
#include "Person.h"

using namespace std;

int main() {

    // Testing Person Class
    Person p1;
    p1.displayInfo();

    Person p2("Joe", 18, "Student");
    p2.displayInfo();
    p2.haveBirthday();

    return 0;
}
