#include <QCoreApplication>
#include <iostream>

// Main function demonstrating the Adapter Pattern.
/*
 *Key Points Explained:
FahrenheitSensor (Adaptee): This class represents an existing component in the system that provides temperature readings in Fahrenheit. It's the class we want to integrate with our system that expects readings in Celsius.

CelsiusSensor (Target Interface): This is the interface that the client code expects to work with. It requires temperature readings to be in Celsius. The Adapter Pattern is used to make the FahrenheitSensor compatible with this interface.

FahrenheitToCelsiusAdapter (Adapter): This class is the core of the Adapter Pattern implementation. It implements the CelsiusSensor interface and contains a reference to a FahrenheitSensor instance. It adapts the interface of FahrenheitSensor to be compatible with the CelsiusSensor interface by converting the temperature reading from Fahrenheit to Celsius.

Main Function: Demonstrates creating a FahrenheitSensor, wrapping it in a FahrenheitToCelsiusAdapter, and then using this adapter to obtain temperature readings in Celsius as expected by the client code.

This example showcases how the Adapter Pattern can effectively bridge the gap between incompatible interfaces, allowing them to communicate seamlessly. It enables the integration of components that otherwise would not work together due to interface incompatibilities, without needing to alter the original components' implementations.
 */

// Adaptee class: Provides temperature readings in Fahrenheit.
class FahrenheitSensor {
public:

    FahrenheitSensor(){
        std::cout << "FahrenheitSensor: I am 77.0 degrees Fahrenheit" << std::endl;
    }
    // Simulates getting a temperature reading in Fahrenheit.
    float getFahrenheitTemperature() const {

        return 77.3; // Example fixed temperature in Fahrenheit.
    }
};

// Target Interface: Defines the interface for temperature readings in Celsius.
class CelsiusSensor {
public:
    virtual ~CelsiusSensor() = default;

    // Method to be implemented by adapters/concrete classes for Celsius temperature.
    virtual float getCelsiusTemperature() const = 0;
};

// Adapter class: Adapts FahrenheitSensor to the CelsiusSensor interface.
class FahrenheitToCelsiusAdapter : public CelsiusSensor {
private:
    const FahrenheitSensor &fahrenheitSensor; // Reference to the adaptee.

public:
    // Constructor: Initializes the adapter with a FahrenheitSensor reference.
    FahrenheitToCelsiusAdapter(const FahrenheitSensor &sensor) : fahrenheitSensor(sensor) {
        std::cout << "FahrenheitToCelsiusAdapter: Instantiated OK" << std::endl;
    }

    // Implements getting temperature in Celsius by converting from Fahrenheit.
    float getCelsiusTemperature() const override {
        // Conversion formula from Fahrenheit to Celsius.
        return (fahrenheitSensor.getFahrenheitTemperature() - 32) * 5 / 9;
    }
};


int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    // Create an instance of the Adaptee class (FahrenheitSensor).
    FahrenheitSensor fahrenheitSensor;

    // Create an Adapter instance, passing in the FahrenheitSensor.
    CelsiusSensor *sensor = new FahrenheitToCelsiusAdapter(fahrenheitSensor);

    std::cout << "Converting Fahrenheit to Celsius..." << std::endl;
    // Use the Adapter to get the temperature in Celsius.
    float celsius = sensor->getCelsiusTemperature();
    std::cout << "Temperature in Celsius: " << celsius << std::endl;

    // Clean up dynamically allocated memory.
    delete sensor;

    std::cout << "---end---" << std::endl;

    return QCoreApplication::exec();
}
