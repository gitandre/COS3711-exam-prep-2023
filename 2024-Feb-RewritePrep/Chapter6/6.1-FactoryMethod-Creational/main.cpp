#include <QCoreApplication>
#include <QDebug>
// FactoryMethodExample.cpp
#include <iostream>

// Product interface
class Product {
public:
    virtual void show() = 0;
};

// ConcreteProductA
class ConcreteProductA : public Product {
public:
    void show() override {
        std::cout << "Product A" << std::endl;
    }
};

// ConcreteProductB
class ConcreteProductB : public Product {
public:
    void show() override {
        std::cout << "Product B" << std::endl;
    }
};

// Creator interface
class Creator {
public:
    virtual Product* factoryMethod() = 0;
};

// ConcreteCreatorA
class ConcreteCreatorA : public Creator {
public:
    Product* factoryMethod() override {
        return new ConcreteProductA();
    }
};

// ConcreteCreatorB
class ConcreteCreatorB : public Creator {
public:
    Product* factoryMethod() override {
        return new ConcreteProductB();
    }
};



int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    Creator* creatorA = new ConcreteCreatorA();
    Product* productA = creatorA->factoryMethod();
    productA->show();

    Creator* creatorB = new ConcreteCreatorB();
    Product* productB = creatorB->factoryMethod();
    productB->show();

    delete productA;
    delete productB;
    delete creatorA;
    delete creatorB;

    return QCoreApplication::exec();
}
