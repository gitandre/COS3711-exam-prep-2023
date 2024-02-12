#include <QCoreApplication>
#include <QDebug>
#include <iostream>

// FacadeExample.cpp
// Subsystem components
class Light {
public:
    void on() {
        std::cout << "Light is on" << std::endl;
    }
    void off() {
        std::cout << "Light is off" << std::endl;
    }
};

class Music {
public:
    void play() {
        std::cout << "Music is playing" << std::endl;
    }
    void off() {
        std::cout << "Music is off" << std::endl;
    }
};

class CoffeeMachine {
public:
    void brew() {
        std::cout << "Coffee is brewing" << std::endl;
    }
    void off() {
        std::cout << "Kettle is off" << std::endl;
    }
};

// Façade
class HomeFacade {
private:
    Light light;
    Music music;
    CoffeeMachine coffee;

public:
    void activate() {
        light.on();
        music.play();
        coffee.brew();
    }

    void deactivate() {
        light.off();
        music.off();
        coffee.off();
    }
};


int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    HomeFacade home;

    std::cout << "Switching on home..." << std::endl;
    home.activate();  // Output: Light is on, Music is playing, Coffee is brewing

    std::cout << "\nSwitching off home..." << std::endl;
    home.deactivate();

    std::cout << "\n---end---" << std::endl;
    return QCoreApplication::exec();
}
