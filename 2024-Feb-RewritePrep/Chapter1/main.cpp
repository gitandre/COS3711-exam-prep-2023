#include <iostream>
#include "Person.h"
#include "SmartPointer.h"
#include "SingletonLogger/SingletonLogger.h"
#include "Connector.h"
#include "polymorphism/ShapePureVirtual.h"
#include "polymorphism/Shape.h"
#include "polymorphism/Circle.h"
#include "polymorphism/Square.h"

void doSignalsAndSlots(SingletonLogger *singletonLogger);

SingletonLogger *doLogging();

using namespace std;

void DoReference() {

    string food = "hamburger";
    string &foodRef = food;
    cout << food << " " << foodRef << endl;
    cout << &food << " " << &foodRef << endl;

    foodRef = "chips";
    cout << food << " " << foodRef << endl;
    cout << &food << " " << &foodRef << endl;

//    hamburger hamburger
//    0x5ffde0 0x5ffde0
//
//    chips chips
//    0x5ffde0 0x5ffde0

}

void printPtr(string *paramPtr) {
    cout << *paramPtr << endl;
    *paramPtr = "printed OK";
}

void DoPointers() {

    string myString = "jonny boo";
    string *stringPtr = &myString;
    printPtr(stringPtr);

    cout << *stringPtr << endl;

}

// templated function to draw all shapes regardless of Shape type
template<typename T>
void DrawShape(T* shape){
    shape->Draw();
}

int main() {

    bool logging = false;
    bool signalAndSlots = false;

    if (logging) {
        SingletonLogger *singletonLogger = doLogging();

        if (signalAndSlots) {

            doSignalsAndSlots(singletonLogger);
        }
    }

    qDebug() << "--Polymorphism start---";

    // ShapePureVirtual spv; // note: cannot instantiate as is an abstract class
    Shape s;
    DrawShape(&s);

    Circle c;
    DrawShape(&c);

    Square sq;
    DrawShape(&sq);

    qDebug() << "--Polymorphism end---";

    qDebug() << "--ENDt---";
    return 0;
}

SingletonLogger *doLogging() {// Create a logger here using a Singleton pattern
    SingletonLogger &logger = SingletonLogger::getInstance();
    SingletonLogger *singletonLogger = &logger;

    logger.log("I log via a singleton");
    logger.log("I log via a singleton also");

    logger.log(SingletonLogger::LogLevel::ERROR, "I am an error :(");


//    DoReference();

//    DoPointers();

//    Person* p1Ptr = new Person("joe",22,"swimmer");
//
//    p1Ptr->displayInfo();
//    delete p1Ptr;

    // Smart Pointer to auto cleanup after it is used
    SmartPointer<Person> person1(new Person());
    person1->displayInfo();
    person1->SetAge(25);
    person1->haveBirthday();

    SingletonLogger::getInstance().log("I also log via a singleton");

    // Print static explanation about a class
//    cout << Person::PersonExplanation() << endl;
//
//    // Instantiate Person Class Def
//    // Very basic OOP example
//    Person p1;
//    Person &p1Ref = p1;
//    p1.displayInfo();
//    p1.haveBirthday();
//
//
//    print("p1Ref prints--------------------");
//    p1Ref.displayInfo();
//    p1Ref.haveBirthday();
//    print("p1Ref prints ends--------------------");
//
//
//    // Instantiate Person Class Params
//    Person p2("Joe", 18, "Student");
//    p2.displayInfo();
//    p2.haveBirthday();
//
//    // loop and create Persons
//    print("Loop and create Persons start---------------------------\n");
//    for (int i = 0; i <= 3; i++) {
//        Person p;
//        cout << "---" << endl;
//    } // these objects go out of scope on each loop by design
//    print("Loop and create Persons end---------------------------\n");
//
//    print("\nFinal Person object count");
//    print("Person Objects = " + to_string(Person::PersonObjectCount()));

    SingletonLogger &logger2 = SingletonLogger::getInstance();
    logger2.log("I am on line 106");
    return singletonLogger;
}

void doSignalsAndSlots(SingletonLogger *singletonLogger) {
    cout << "\nBasic Signal and Slot =================================" << endl;
    Sender *sender = new Sender();
    Receiver *receiver = new Receiver();
//    SingletonLogger* ptr = &logger2;

    // connect sender to Receiver
    QObject::connect(sender, &Sender::mySignal, receiver, &Receiver::mySlot);

    // connect Sender to Logger :)
    QObject::connect(sender, &Sender::mySignal, singletonLogger, &SingletonLogger::mySlot);

    // Send some signals
    sender->sendSomething();
}



