cmake_minimum_required(VERSION 3.26)
project(ass3_udp_receiver_application)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "C:/Qt/6.6.1/mingw_64/bin")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        Xml
        Network
        REQUIRED)

add_executable(ass3_udp_receiver_application main.cpp
        MainWindow.h
        MainWindow.cpp)
target_link_libraries(ass3_udp_receiver_application
        Qt::Core
        Qt::Gui
        Qt::Widgets
        Qt6::Xml
        Qt6::Network
)

