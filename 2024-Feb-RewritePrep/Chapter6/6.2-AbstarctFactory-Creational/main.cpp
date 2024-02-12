#include <QCoreApplication>
#include <QDebug>
// AbstractFactoryExample.cpp
#include <iostream>

// Abstract Product A
class ProductA {
public:
    virtual void show() = 0;
};

// Concrete Product A1
class ProductA1 : public ProductA {
public:
    void show() override {
        std::cout << "Product A1" << std::endl;
    }
};

// Concrete Product A2
class ProductA2 : public ProductA {
public:
    void show() override {
        std::cout << "Product A2" << std::endl;
    }
};

// Abstract Product B
class ProductB {
public:
    virtual void display() = 0;
};

// Concrete Product B1
class ProductB1 : public ProductB {
public:
    void display() override {
        std::cout << "Product B1" << std::endl;
    }
};

// Concrete Product B2
class ProductB2 : public ProductB {
public:
    void display() override {
        std::cout << "Product B2" << std::endl;
    }
};

// Abstract Factory
class AbstractFactory {
public:
    virtual ProductA* createProductA() = 0;
    virtual ProductB* createProductB() = 0;
};

// Concrete Factory 1
class ConcreteFactory1 : public AbstractFactory {
public:
    ProductA* createProductA() override {
        return new ProductA1();
    }
    ProductB* createProductB() override {
        return new ProductB1();
    }
};

// Concrete Factory 2
class ConcreteFactory2 : public AbstractFactory {
public:
    ProductA* createProductA() override {
        return new ProductA2();
    }
    ProductB* createProductB() override {
        return new ProductB2();
    }
};

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    AbstractFactory* factory1 = new ConcreteFactory1();
    ProductA* productA1 = factory1->createProductA();
    ProductB* productB1 = factory1->createProductB();
    productA1->show();
    productB1->display();

    AbstractFactory* factory2 = new ConcreteFactory2();
    ProductA* productA2 = factory2->createProductA();
    ProductB* productB2 = factory2->createProductB();
    productA2->show();
    productB2->display();

    delete productA1;
    delete productB1;
    delete factory1;

    delete productA2;
    delete productB2;
    delete factory2;

    return QCoreApplication::exec();
}
