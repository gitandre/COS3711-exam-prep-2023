#include <QCoreApplication>
#include <QDebug>
// SingletonExample.cpp
#include <iostream>

// Singleton Class
class Singleton {
private:
    // Private Constructor
    Singleton() {
        std::cout << "Singleton Instance Created" << std::endl;
    }

    // Private Copy Constructor and Assignment Operator
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

public:
    // Public Method to access the single instance
    // Returns a reference
    static Singleton& getInstance() {
        static Singleton instance;  // Guaranteed to be lazy-initialized and destroyed correctly
        return instance;
    }

    void show() {
        std::cout << "I am a Singleton not a simpleton!!!, with address = " << &this->getInstance() << std::endl;
    }
};


int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

        // Try to get Singleton instances
    Singleton& s1 = Singleton::getInstance();
    Singleton& s2 = Singleton::getInstance();

    // Check if they are the same instance
    if (&s1 == &s2) {
        std::cout << "Both are the same instance" << std::endl;
    }

    s1.show();
    s2.show();

    return QCoreApplication::exec();
}
