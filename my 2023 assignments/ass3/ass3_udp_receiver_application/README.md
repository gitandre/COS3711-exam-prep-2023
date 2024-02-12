# UDP Receiver Application

## Overview

This is a Qt6 application that listens for incoming UDP messages and displays the received data in a QTextEdit widget. The application uses QUdpSocket for handling UDP communication.

## Requirements

- Qt6
- CMake 3.26 or higher
- C++17

## Features

- Listens for UDP messages on a specific port.
- Displays received messages in real-time.
- Offers a "Clear" button to clear the display area.

## Compilation and Execution

1. Navigate to the project's root directory.
2. Run `cmake .` to generate the Makefile.
3. Run `make` to compile the project.
4. Execute the compiled binary.

## Project Structure

- `main.cpp`: Entry point of the application.
- `MainWindow.h` and `MainWindow.cpp`: Main window of the application that contains all UI elements and UDP socket logic.

## Usage

1. Run the application.
2. Send UDP messages to the specified port from the sender app.
3. Observe received messages in the main window.

---