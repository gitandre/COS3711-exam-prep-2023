## Design Patterns

### 1. Factory method Pattern (Creational)

The Factory Method pattern is a creational design pattern that provides an interface for creating objects but allows subclasses to alter the type of objects that will be created. This pattern is commonly used in libraries and frameworks where implementation details are expected to be extended by client code

```c++
#include <QCoreApplication>
#include <QDebug>
#include <QString>

// Base class for all shapes
class Shape {
public:
    virtual ~Shape() {}
    virtual QString draw() = 0;
};

// Rectangle class
class Rectangle : public Shape {
public:
    QString draw() override {
        return "Drawing a rectangle";
    }
};

// Circle class
class Circle : public Shape {
public:
    QString draw() override {
        return "Drawing a circle";
    }
};

// ShapeFactory class - This is the Factory Method
class ShapeFactory {
public:
    enum ShapeType {
        RECTANGLE,
        CIRCLE
    };

    static Shape* createShape(ShapeType type) {
        Shape *shape = nullptr;

        switch (type) {
            case RECTANGLE:
                shape = new Rectangle();
                break;
            case CIRCLE:
                shape = new Circle();
                break;
        }

        return shape;
    }
};

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    // Create Rectangle
    Shape *rectangle = ShapeFactory::createShape(ShapeFactory::RECTANGLE);
    if (rectangle) {
        qDebug() << rectangle->draw();
        delete rectangle;
    }

    // Create Circle
    Shape *circle = ShapeFactory::createShape(ShapeFactory::CIRCLE);
    if (circle) {
        qDebug() << circle->draw();
        delete circle;
    }

    return a.exec();
}

```

---

### 2. Abstract Factory Pattern (Creational)

The Abstract Factory pattern provides an interface for creating families of related or dependent objects without specifying their concrete classes. This pattern is particularly useful when the system needs to be independent of how its objects are created, composed, and represented.

```c++
#include <QCoreApplication>
#include <QDebug>
#include <QString>

// Shape Interface
class Shape {
public:
    virtual ~Shape() {}
    virtual QString draw() = 0;
};

// Concrete Shape Classes
class Rectangle : public Shape {
public:
    QString draw() override {
        return "Drawing a rectangle";
    }
};

class Circle : public Shape {
public:
    QString draw() override {
        return "Drawing a circle";
    }
};

// Color Interface
class Color {
public:
    virtual ~Color() {}
    virtual QString fill() = 0;
};

// Concrete Color Classes
class Red : public Color {
public:
    QString fill() override {
        return "Filling with red color";
    }
};

class Blue : public Color {
public:
    QString fill() override {
        return "Filling with blue color";
    }
};

// Abstract Factory
class AbstractFactory {
public:
    virtual Shape* createShape() = 0;
    virtual Color* createColor() = 0;
};

// Concrete Factories
class ShapeFactory : public AbstractFactory {
public:
    Shape* createShape() override {
        return new Rectangle();
    }
    Color* createColor() override {
        return nullptr; // This factory doesn't deal with colors
    }
};

class ColorFactory : public AbstractFactory {
public:
    Shape* createShape() override {
        return nullptr; // This factory doesn't deal with shapes
    }
    Color* createColor() override {
        return new Blue();
    }
};

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    // Create a shape using the shape factory
    AbstractFactory* shapeFactory = new ShapeFactory();
    Shape* shape = shapeFactory->createShape();
    if (shape) {
        qDebug() << shape->draw();
        delete shape;
    }
    delete shapeFactory;

    // Create a color using the color factory
    AbstractFactory* colorFactory = new ColorFactory();
    Color* color = colorFactory->createColor();
    if (color) {
        qDebug() << color->fill();
        delete color;
    }
    delete colorFactory;

    return a.exec();
}

```

---

### 3. Singleton (Creational Pattern)

The Singleton design pattern ensures that a class has only one instance and provides a global point of access to it. It's useful for things like database connections, logging, driver objects, caching, thread pools, or anything else that should only have a single instance.

```c++
#include <QCoreApplication>
#include <QDebug>
#include <QString>

class Logger {
public:
    // Delete copy constructor and assignment operator to prevent multiple instances
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

    // Public method to get the single instance of Logger
    static Logger& instance() {
        static Logger instance; // Guaranteed to be destroyed, instantiated on first use.
        return instance;
    }

    void log(const QString& message) {
        qDebug() << "Log: " << message;
    }

private:
    // Make constructor private to prevent direct instantiation
    Logger() {}
};

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    // Log a message
    Logger::instance().log("This is a singleton logger.");

    // Attempt to create another instance (will not work)
    // Logger anotherLogger = Logger::instance(); // Compiler error

    return a.exec();
}

```

---

### 4. Memento (Behavioral Pattern)

The Memento design pattern is used to capture and externalize an object's internal state so that the object can be restored to this state later. It is particularly useful for implementing mechanisms such as undo mechanisms.

```c++
#include <QCoreApplication>
#include <QDebug>
#include <QString>
#include <QStack>

// Memento class to hold the editor state
class Memento {
public:
    Memento(const QString& state) : state(state) {}
    QString getState() const {
        return state;
    }
private:
    QString state;
};

// Originator class (TextEditor)
class TextEditor {
public:
    TextEditor() : content("") {}
    void write(const QString& words) {
        content += words;
    }
    QString read() const {
        return content;
    }
    Memento save() const {
        return Memento(content);
    }
    void restore(const Memento& memento) {
        content = memento.getState();
    }
private:
    QString content;
};

// Caretaker class
class Caretaker {
public:
    void undo(TextEditor& editor) {
        if (!savedStates.isEmpty()) {
            editor.restore(savedStates.pop());
        }
    }
    void saveState(const TextEditor& editor) {
        savedStates.push(editor.save());
    }
private:
    QStack<Memento> savedStates;
};

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    TextEditor editor;
    Caretaker caretaker;

    editor.write("First sentence. ");
    qDebug() << "Content: " << editor.read();

    caretaker.saveState(editor);
    editor.write("Second sentence. ");
    qDebug() << "Content: " << editor.read();

    caretaker.saveState(editor);
    editor.write("Third sentence. ");
    qDebug() << "Content: " << editor.read();

    caretaker.undo(editor);
    qDebug() << "After undo: " << editor.read();

    caretaker.undo(editor);
    qDebug() << "After another undo: " << editor.read();

    return a.exec();
}

```

---

### 5. Strategy (Behavioral Pattern)

The Strategy design pattern defines a family of algorithms, encapsulates each one, and makes them interchangeable. Strategy lets the algorithm vary independently from the context that uses the algorithm.

```c++
#include <QCoreApplication>
#include <QDebug>
#include <QVector>

// Strategy interface
class SortStrategy {
public:
    virtual ~SortStrategy() {}
    virtual void sort(QVector<int>& data) = 0;
};

// Concrete Strategy 1: Quick Sort
class QuickSort : public SortStrategy {
public:
    void sort(QVector<int>& data) override {
        // Quick sort algorithm (simplified)
        qSort(data.begin(), data.end());
    }
};

// Concrete Strategy 2: Bubble Sort
class BubbleSort : public SortStrategy {
public:
    void sort(QVector<int>& data) override {
        // Bubble sort algorithm (simplified)
        int n = data.size();
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < n - i - 1; ++j) {
                if (data[j] > data[j + 1]) {
                    qSwap(data[j], data[j + 1]);
                }
            }
        }
    }
};

// Context class
class Context {
public:
    Context(SortStrategy* strategy) : strategy(strategy) {}
    ~Context() {
        delete strategy;
    }
    void setStrategy(SortStrategy* newStrategy) {
        delete strategy;
        strategy = newStrategy;
    }
    void executeStrategy(QVector<int>& data) {
        strategy->sort(data);
    }
private:
    SortStrategy* strategy;
};

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    QVector<int> data {5, 1, 9, 3, 7, 6, 8, 2, 4, 0};

    // Using QuickSort strategy
    Context context(new QuickSort());
    context.executeStrategy(data);
    qDebug() << "QuickSort result:" << data;

    // Switching to BubbleSort strategy
    context.setStrategy(new BubbleSort());
    context.executeStrategy(data);
    qDebug() << "BubbleSort result:" << data;

    return a.exec();
}

```

---

### 6. Adapter/Wrapper (Structural Pattern)

The Adapter pattern allows incompatible interfaces to work together. This pattern involves a single class, called Adapter, which joins functionalities of independent or incompatible interfaces.

```c++
#include <QCoreApplication>
#include <QDebug>
#include <QString>

// MediaPlayer interface
class MediaPlayer {
public:
    virtual ~MediaPlayer() {}
    virtual void play(const QString& audioType, const QString& fileName) = 0;
};

// AdvancedMediaPlayer interface
class AdvancedMediaPlayer {
public:
    virtual ~AdvancedMediaPlayer() {}
    virtual void playMp4(const QString& fileName) = 0;
    virtual void playMkv(const QString& fileName) = 0;
};

// Concrete class implementing AdvancedMediaPlayer
class AdvancedPlayer : public AdvancedMediaPlayer {
public:
    void playMp4(const QString& fileName) override {
        qDebug() << "Playing mp4 file: " << fileName;
    }
    void playMkv(const QString& fileName) override {
        qDebug() << "Playing mkv file: " << fileName;
    }
};

// Adapter class
class MediaAdapter : public MediaPlayer {
public:
    MediaAdapter(const QString& audioType) {
        if (audioType == "mp4" || audioType == "mkv") {
            advancedPlayer = new AdvancedPlayer();
        }
    }

    ~MediaAdapter() {
        delete advancedPlayer;
    }

    void play(const QString& audioType, const QString& fileName) override {
        if (audioType == "mp4") {
            advancedPlayer->playMp4(fileName);
        } else if (audioType == "mkv") {
            advancedPlayer->playMkv(fileName);
        }
    }

private:
    AdvancedMediaPlayer* advancedPlayer = nullptr;
};

// Concrete class implementing MediaPlayer and using Adapter
class AudioPlayer : public MediaPlayer {
public:
    void play(const QString& audioType, const QString& fileName) override {
        if (audioType == "mp3") {
            qDebug() << "Playing mp3 file: " << fileName;
        } else if (audioType == "mp4" || audioType == "mkv") {
            MediaAdapter adapter(audioType);
            adapter.play(audioType, fileName);
        } else {
            qDebug() << "Invalid media type: " << audioType;
        }
    }
};

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    AudioPlayer player;
    player.play("mp3", "song.mp3");
    player.play("mp4", "video.mp4");
    player.play("mkv", "movie.mkv");
    player.play("avi", "clip.avi");

    return a.exec();
}

```

---

### 7.Facade (Structural Pattern)

The Facade pattern provides a simplified interface to a set of interfaces in a subsystem. The Facade defines a higher-level interface that makes the subsystem easier to use by wrapping complex subsystem functionality in a simpler interface.

```c++
#include <QCoreApplication>
#include <QDebug>

// Subsystem 1: Light
class Light {
public:
    void on() {
        qDebug() << "Light is ON";
    }
    void off() {
        qDebug() << "Light is OFF";
    }
};

// Subsystem 2: AirConditioner
class AirConditioner {
public:
    void on() {
        qDebug() << "AirConditioner is ON";
    }
    void off() {
        qDebug() << "AirConditioner is OFF";
    }
};

// Subsystem 3: SecuritySystem
class SecuritySystem {
public:
    void activate() {
        qDebug() << "SecuritySystem is Activated";
    }
    void deactivate() {
        qDebug() << "SecuritySystem is Deactivated";
    }
};

// Facade: SmartHomeFacade
class SmartHomeFacade {
public:
    SmartHomeFacade() {
        light = new Light();
        airConditioner = new AirConditioner();
        securitySystem = new SecuritySystem();
    }

    ~SmartHomeFacade() {
        delete light;
        delete airConditioner;
        delete securitySystem;
    }

    void leaveHome() {
        qDebug() << "Leaving home...";
        light->off();
        airConditioner->off();
        securitySystem->activate();
    }

    void comeHome() {
        qDebug() << "Coming home...";
        light->on();
        airConditioner->on();
        securitySystem->deactivate();
    }

private:
    Light* light;
    AirConditioner* airConditioner;
    SecuritySystem* securitySystem;
};

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    SmartHomeFacade smartHome;
    smartHome.leaveHome();
    smartHome.comeHome();

    return a.exec();
}

```

---

### 9.Serializer

Serialization is the process of converting an object's state to a byte stream, and the opposite operation of creating an object from a byte stream is deserialization.

```c++
#include <QCoreApplication>
#include <QFile>
#include <QDataStream>
#include <QDebug>

class Person {
public:
    QString name;
    int age;
    QString email;

    // Serialize the object
    friend QDataStream& operator<<(QDataStream& stream, const Person& person) {
        stream << person.name << person.age << person.email;
        return stream;
    }

    // Deserialize the object
    friend QDataStream& operator>>(QDataStream& stream, Person& person) {
        stream >> person.name >> person.age >> person.email;
        return stream;
    }
};

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    // Create a Person object
    Person person;
    person.name = "John";
    person.age = 30;
    person.email = "john@example.com";

    // Serialize the object to a file
    QFile file("person.dat");
    if (file.open(QIODevice::WriteOnly)) {
        QDataStream out(&file);
        out << person;
        file.close();
        qDebug() << "Serialization done.";
    } else {
        qDebug() << "Could not open file for serialization.";
    }

    // Deserialize the object from the file
    Person newPerson;
    if (file.open(QIODevice::ReadOnly)) {
        QDataStream in(&file);
        in >> newPerson;
        file.close();
        qDebug() << "Deserialization done.";
    } else {
        qDebug() << "Could not open file for deserialization.";
    }

    // Display the deserialized object
    qDebug() << "Deserialized Person:";
    qDebug() << "Name:" << newPerson.name;
    qDebug() << "Age:" << newPerson.age;
    qDebug() << "Email:" << newPerson.email;

    return a.exec();
}

```