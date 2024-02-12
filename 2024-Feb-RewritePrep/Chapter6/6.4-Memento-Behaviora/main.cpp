#include <QCoreApplication>
#include <QDebug>
#include <iostream>
#include <vector>
#include <memory>

// Memento class stores the state of the Originator.
class Memento {
private:
    std::string state; // Internal state of the Originator at a moment in time.

public:
    // Constructor that initializes the Memento with a state.
    Memento(const std::string& state) : state(state) {}

    // Retrieves the stored state.
    std::string getState() const {
        return state;
    }
};

// Originator class whose state changes over time and can be saved/restored.
class Originator {
private:
    std::string state; // Current state of the Originator.

public:
    // Constructor to initialize the Originator with an initial state.
    Originator(const std::string& s) : state(s) {}

    // Creates a Memento object containing a snapshot of the current state.
    std::shared_ptr<Memento> createMemento() {
        return std::make_shared<Memento>(state);
    }

    // Restores the Originator's state from a Memento object.
    void restoreMemento(std::shared_ptr<Memento> memento) {
        state = memento->getState();
    }

    // Sets the Originator's current state.
    void setState(const std::string& s) {
        state = s;
    }

    // Displays the Originator's current state.
    void showState() {
        std::cout << "Current State: " << state << std::endl;
    }
};

// Caretaker class manages the saving and undoing of the Originator's states.
class Caretaker {
private:
    std::vector<std::shared_ptr<Memento>> mementoList; // List to store Mementos.
    Originator& originator; // Reference to the Originator.

public:
    // Constructor initializes the Caretaker with an Originator.
    Caretaker(Originator& o) : originator(o) {}

    // Saves the current state of the Originator as a Memento.
    void save() {
        mementoList.push_back(originator.createMemento());
    }

    // Restores the Originator's state to the last saved state.
    void undo() {
        if (!mementoList.empty()) {

            // runs twice as the last saved state needs to be removed and land on the 2nd last one
            for (int i=0; i <= 1 && !mementoList.empty();i++) {
                std::shared_ptr<Memento> memento = mementoList.back();
                originator.restoreMemento(memento);
                mementoList.pop_back(); // Remove the last Memento after restoring.
            }
        }
    }
};

// Client code demonstrates using the Memento Pattern.
int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    Originator originator("Initial State"); // Create Originator with an initial state.
    Caretaker caretaker(originator); // Create Caretaker to manage Originator's states.
    caretaker.save(); // Save the current state.
    originator.showState(); // Display initial state.

    originator.setState("Save 1"); // Modify the state.
    caretaker.save(); // Save the current state.
    originator.showState(); // Display initial state.

    originator.setState("Save 2"); // Modify the state.
    caretaker.save(); // Save the current state.
    originator.showState(); // Display initial state.

    originator.setState("Save 3"); // Modify the state.
    caretaker.save(); // Save the current state.
    originator.showState(); // Display initial state.

    std::cout << "\nLet's Undo stuff-----------------------" << std::endl;
    std::cout << "Undo...once" << std::endl;
    caretaker.undo(); // Undo the modification by restoring the last saved state.
    caretaker.save();
    originator.showState(); // Display restored state.

    std::cout << "Undo...a second time" << std::endl;
    caretaker.undo(); // Undo the modification by restoring the last saved state.
    caretaker.save();
    originator.showState(); // Display restored state.

    std::cout << "Undo...a third time" << std::endl;
    std::cout << "We should be back at 'Initial State' :)" << std::endl;
    caretaker.undo(); // Undo the modification by restoring the last saved state.
    caretaker.save();
    originator.showState(); // Display restored state.

    return QCoreApplication::exec();
}
