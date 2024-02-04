#include <iostream>
#include "Person.h"

using namespace std;

int main() {

    // Testing Person Class
    int x = 0;

    Person p1(x);
    p1.displayInfo();

    x = 1976;
    Person p2("Joe", 18,x,"Student");
    p2.displayInfo();
    p2.haveBirthday();

    return 0;
}
