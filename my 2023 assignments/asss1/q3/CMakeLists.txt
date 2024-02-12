cmake_minimum_required(VERSION 3.25)
project(cos3711_ass1_q3)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "C:/Qt/6.6.1/mingw_64/bin")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(cos3711_ass1_q3 main.cpp MyMainWin.h MyMainWin.cpp MyAlbum.h MyAlbumModel.cpp MyAlbumModel.h)
target_link_libraries(cos3711_ass1_q3
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )

