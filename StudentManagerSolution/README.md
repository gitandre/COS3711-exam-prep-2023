# Student Manager Solution

## Description

This project aims to create a student management system using C++ and Qt6. The system will manage records for students, student advisors, modules, and degrees. It demonstrates the use of Object-Oriented Programming (OOP) principles, XML for data storage, and the Singleton design pattern for database management.

## Setup Instructions

1. Clone the repository to your local machine.
2. Open the project in your preferred C++ IDE that supports Qt6.
3. Build and run the project.

## File Structure

- `main.cpp`: Entry point of the application
- `dbManager/`
    - `DatabaseManager.h`: Header file for the DatabaseManager class
    - `DatabaseManager.cpp`: Implementation file for the DatabaseManager class
- `xml/`
    - `Student.xml`: XML file for storing student records
    - `Student.xml`: XML file for storing student advisor records
    - `Module.xml`: XML file for storing module records
    - `Degree.xml`: XML file for storing degree records

## Features

- CRUD operations for each entity: Student, StudentAdvisor, Module, and Degree.
- Singleton pattern for database management.
- XML-based data storage.
- Utility functions for reading and writing XML files.

## Future Enhancements

- Add user authentication.
- Implement search functionality.
- Add a GUI using Qt6 Widgets.
- more coming soon...

