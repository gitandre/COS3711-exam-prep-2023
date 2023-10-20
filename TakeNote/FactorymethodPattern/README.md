
## Factory Method Pattern:

### Basic Structure

- Created a `Note` class that holds the title and content of a note.
- Created a `NoteManager` class that manages a list of notes and provides methods to create and list notes.

### Factory Method Pattern

- Introduced an interface `NoteFactory` with a method `createNote()` for creating `Note` objects.
- Created two concrete factories `TextNoteFactory` and `ChecklistNoteFactory` that implement the `createNote()` method.

### How It Works

- `NoteManager` is initialized with a `NoteFactory` object.
- When `createNote()` is called on `NoteManager`, it delegates the actual creation of the `Note` object to the factory it has been initialized with.
- This allows the type of notes being created to be changed at runtime by switching out the factory.

### Object Lifetimes and Qt Features

- Both `Note` and `NoteManager` classes inherit from `QObject`, allowing for future use of Qt features like signals and slots.

### Demonstration in `main()`

- In the `main()` function, we created instances of `TextNoteFactory` and `ChecklistNoteFactory`.
- We also created a `NoteManager` and demonstrated how to create different types of notes by changing its factory.

---

