#include <QCoreApplication>
#include <QDebug>
// SingletonExample.cpp
#include <iostream>

// SingletonLogger Class
class SingletonLogger {
private:
    // Private Constructor
    SingletonLogger() {
        std::cout << "SingletonLogger Instance Created" << std::endl;
    }

    // Private Copy Constructor and Assignment Operator
    SingletonLogger(const SingletonLogger &) = delete;

    SingletonLogger &operator=(const SingletonLogger &) = delete;

public:
    // Public Method to access the single instance
    // Returns a reference
    static SingletonLogger &getInstance() {
        static SingletonLogger instance;  // Guaranteed to be lazy-initialized and destroyed correctly
        return instance;
    }

    void slog(std::string msg) {
        std::cout << "I am a SingletonLogger not a simpleton!!!, with address = " << &this->getInstance() << " [log ->] "
                  << msg << std::endl;
    }
};

// A base class that includes a reference to the Singleton logger
class BaseAny {
public:
    BaseAny() {}

    void doLogging(std::string msg) {
        std::cout << "BaseAny.doLogging()..." << std::endl;
        m_logger.slog(msg);
    }

private:
    SingletonLogger &m_logger = SingletonLogger::getInstance();
};

// Inherits from BaseAny and hence can log using the
class Foo : public BaseAny {

public:
    Foo() {}

};

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    Foo f1;
    f1.doLogging("I am f1 logging");
    // Try to get SingletonLogger instances
    SingletonLogger &s1 = SingletonLogger::getInstance();
    SingletonLogger &s2 = SingletonLogger::getInstance();

    // Check if they are the same instance
    if (&s1 == &s2) {
        std::cout << "Both are the same instance" << std::endl;
    }

    s1.slog("s1 logs");
    s2.slog("s2 logs");

    return QCoreApplication::exec();
}
