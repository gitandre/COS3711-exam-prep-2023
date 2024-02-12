#include <QCoreApplication>
#include <iostream>
#include <string>
#include <random>

// Abstract Component for Button
class Button {
public:
    virtual void paint() = 0;
};

// Abstract Component for Player
class Player {
public:
    virtual void play() = 0;
};

// Concrete Component for Windows
class WindowsButton : public Button {
public:
    void paint() override {
        std::cout << "Rendering a button in Windows style." << std::endl;
    }
};

class WindowsPlayer : public Player {
public:
    void play() override {
        std::cout << "Playing media in Windows style." << std::endl;
    }
};

// Concrete Component for MacOS
class MacOSButton : public Button {
public:
    void paint() override {
        std::cout << "Rendering a button in MacOS style." << std::endl;
    }
};

class MacOSPlayer : public Player {
public:
    void play() override {
        std::cout << "Playing media in MacOS style." << std::endl;
    }
};

// GUIFactory Interface
class GUIFactory {
public:
    virtual Button *createButton() = 0;

    virtual Player *createPlayer() = 0;
};

// Concrete Factories
class WindowsFactory : public GUIFactory {
public:
    Button *createButton() override {
        return new WindowsButton();
    }

    Player *createPlayer() override {
        return new WindowsPlayer();
    }
};

class MacOSFactory : public GUIFactory {
public:
    Button *createButton() override {
        return new MacOSButton();
    }

    Player *createPlayer() override {
        return new MacOSPlayer();
    }
};

// Factory Producer
class FactoryProducer {
public:
    static GUIFactory *getFactory(const std::string &type) {
        if (type == "Win") {
            return new WindowsFactory();
        } else if (type == "MacOS") {
            return new MacOSFactory();
        } else {
            return nullptr;
        }
    }
};

// function to test producer
std::string getRandomOS() {
    // Create a random device and use it to seed a generator
    std::random_device rd;
    std::mt19937 gen(rd());

    // Define a distribution that has two equally likely outcomes
    std::uniform_int_distribution<> dis(0, 1);

    // Use the distribution to generate a random number (0 or 1) and map it to OS names
    if (dis(gen) == 0) {
        return "Win";
    } else {
        return "MacOS";
    }
}


int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    // Get the OS type randomly
    std::string osType = getRandomOS();

    GUIFactory *factory = FactoryProducer::getFactory(osType);
    if (factory != nullptr) {
        Button *button = factory->createButton();
        button->paint();

        Player *player = factory->createPlayer();
        player->play();

        // Clean up
        delete button;
        delete player;
        delete factory;
    } else {
        std::cout << "Unknown OS type provided." << std::endl;
    }

    return a.exec();
}
