cmake_minimum_required(VERSION 3.26)
project(ass3_gui_application)

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

add_executable(ass3_gui_application main.cpp
        MyStoreApp.h
        MyStoreApp.cpp
        AddMyItemDialog.h
        AddMyItemDialog.cpp
        MyItem.cpp
        MyItem.h
        MyItemListDialog.h
        MyItemListDialog.cpp
        MyTransactionFormDialog.cpp
        MyTransactionFormDialog.h
        MyTransactionLineItem.cpp
        MyTransactionLineItem.h
        MyTransaction.cpp
        MyTransaction.h
        MyTransactionTreeViewWidget.h
        MyTransactionTreeViewWidget.cpp)
target_link_libraries(ass3_gui_application
        Qt::Core
        Qt::Gui
        Qt::Widgets
        Qt6::Xml
        Qt6::Core
        Qt6::Network
)

