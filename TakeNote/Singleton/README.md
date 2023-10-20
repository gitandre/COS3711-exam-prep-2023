## Singleton Logger


### Structure:

- The `Logger` class inherits from `QObject` to enable Qt features like signals and slots.
- A private static member `instance` is used to hold the single instance of `Logger`.
- The constructor is made private to prevent other classes from creating new instances.

### Singleton Implementation:

- The `getInstance()` static method checks if an instance already exists.
    - If not, it creates one using the private constructor.
    - It then returns the existing or newly created instance.

### Logging with Timestamp:

- The `logEvent()` method takes a string as input (the event to be logged).
- It fetches the current date and time, formats it as a string, and outputs it along with the event using `qDebug()`.

### Key Features:

- The `static inline Logger* instance` ensures there's only one instance of `Logger`.
- The method `getInstance()` provides a global point of access to this instance.
- The timestamp provides a temporal context to each log entry.

By doing this, we ensure that all logging throughout the application goes through this single `Logger` instance, making it easier to manage and extend logging functionality in the future.

Would you like to move on to the next design pattern, or is there anything else you'd like to discuss?