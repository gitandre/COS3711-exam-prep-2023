# OOP and C++


### 1. Encapsulation
- **What It Is**: Encapsulation is the bundling of data (attributes) and methods (functions) that manipulate the data into a single unit called an object.
- **Why It's Useful**: It provides control over the data by restricting unauthorized access and modification.

### 2. Abstraction
- **What It Is**: Abstraction means exposing only the essential features of an object while hiding the unnecessary details.
- **Why It's Useful**: It simplifies complex systems by breaking them down into manageable parts, allowing you to focus on interactions at a higher level.

### 3. Inheritance
- **What It Is**: Inheritance allows a class (the subclass) to use methods and properties of another class (the superclass).
- **Why It's Useful**: It promotes code reusability and can be used to model 'is-a' relationships between objects.

### 4. Polymorphism
- **What It Is**: Polymorphism allows objects of different classes to be treated as objects of a common superclass. There are several types of polymorphism, including method overriding and overloading.
- **Why It's Useful**: It provides a way to implement elegant software design patterns, making it easier to scale and add functionalities to systems.

Each of these principles serves to help programmers create more efficient, secure, and maintainable code.

**Inheritance and polymorphism are closely linked** concepts in object-oriented programming, and they often work hand-in-hand to produce efficient and maintainable code. Here's a brief explanation of how they are related:

### Inheritance and 'Is-A' Relationship
Inheritance establishes an "is-a" relationship between the base class (superclass) and the derived class (subclass). For example, if you have a base class `Animal` and a derived class `Dog`, the derived class `Dog` is a type of `Animal`.

### Polymorphism and Dynamic Binding
Polymorphism takes advantage of inheritance by allowing you to use a base class reference to interact with objects of the derived class. This is particularly useful when you have multiple derived classes and you want to treat them as objects of their common base class. The actual method that gets called is determined at runtime, a feature known as dynamic binding.

### Example
Consider the following C++ example:

```cpp
class Animal {
public:
    virtual void makeSound() {
        std::cout << "Animal sound\n";
    }
};

class Dog : public Animal {
public:
    void makeSound() override {
        std::cout << "Woof\n";
    }
};

class Cat : public Animal {
public:
    void makeSound() override {
        std::cout << "Meow\n";
    }
};

void animalSound(Animal* animal) {
    animal->makeSound();
}

int main() {
    Animal a;
    Dog d;
    Cat c;

    animalSound(&a);  // Output: Animal sound
    animalSound(&d);  // Output: Woof
    animalSound(&c);  // Output: Meow

    return 0;
}
```

In this example, the `animalSound` function can accept any object of type `Animal` or its subclasses (`Dog`, `Cat`). The correct `makeSound` method is called based on the actual object type, demonstrating polymorphism.

### Summary
- **Inheritance** allows you to define a new class based on an existing class, promoting code reusability.
- **Polymorphism** allows you to use objects of different classes interchangeably, promoting code flexibility and maintainability.

Together, they enable more modular and scalable code design.

### is a... vs has a...
"Is-A": This term is associated with inheritance and implies that a subclass is a specialized form of the superclass.

"Has-A": This term is associated with composition, indicating that a class contains instances of other classes as members.

Encapsulation: This is a separate concept that involves bundling data and methods into a single unit and controlling access to the data.

### Class key words explained

Below is a C++ code example that includes many of the keywords and constructs used in defining a class, with comments to explain each one.

```cpp
// Using the 'class' keyword to define a new class type.
class BaseClass {
public: // Public access specifier
    // Default constructor
    BaseClass() {
        // Constructor code
    }

    // Virtual function: Can be overridden by derived classes
    virtual void show() {
        // Function code
    }

    // Destructor: Cleans up resources when an object is destroyed
    virtual ~BaseClass() {
        // Destructor code
    }
};

// Using the 'class' keyword again to define another class type.
// Using ': public' to indicate public inheritance from BaseClass
class DerivedClass : public BaseClass {
private: // Private access specifier
    int privateVar; // Private member variable

protected: // Protected access specifier
    int protectedVar; // Protected member variable

public:
    // Parameterized constructor
    DerivedClass(int a, int b) : privateVar(a), protectedVar(b) {
        // Constructor code
    }

    // Overriding the virtual function from the base class
    // Using 'override' keyword to ensure we're overriding
    void show() override {
        // Function code
    }

    // Final function: Cannot be overridden by further derived classes
    virtual void finalFunction() final {
        // Function code
    }

    // Destructor: Overrides the base class destructor
    // Using 'override' keyword to ensure we're overriding
    ~DerivedClass() override {
        // Destructor code
    }
};

// Using 'final' with a class to indicate it cannot be inherited from
class FinalClass final : public DerivedClass {
public:
    // Constructor: Calls the parameterized constructor of the base class
    FinalClass(int a, int b) : DerivedClass(a, b) {
        // Constructor code
    }
};

int main() {
    // Creating an object of the base class
    BaseClass baseObj;

    // Creating an object of the derived class
    DerivedClass derivedObj(1, 2);

    // Creating an object of the final class
    FinalClass finalObj(3, 4);

    // Using a pointer to base class for polymorphic behavior
    BaseClass* ptr = &derivedObj;
    ptr->show(); // Calls the show function of DerivedClass

    return 0;
}
```

This example doesn't cover every possible keyword or feature that can be used in a class (C++ is a very rich language), but it does cover the most commonly used ones for defining classes and inheritance hierarchies.