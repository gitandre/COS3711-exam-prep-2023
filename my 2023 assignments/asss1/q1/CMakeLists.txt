cmake_minimum_required(VERSION 3.25)
project(ass1_q1)

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

add_executable(ass1_q1 main.cpp MyStaffMember.h Staffmember.cpp MyStaffMemberModel.h MyStaffMemberModel.cpp MyMainWin.cpp MyMainWin.h Staffmember.cpp)
target_link_libraries(ass1_q1
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )

