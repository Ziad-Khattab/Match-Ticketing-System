cmake_minimum_required(VERSION 3.16)
project(SportsTicketing)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 COMPONENTS Widgets REQUIRED)

add_executable(SportsTicketing
    main.cpp
    MainWindow.cpp
    MainWindow.h
    Match.cpp
    Match.h
    Ticket.cpp
    Ticket.h
)

# The fix is here: PRIVATE must be all uppercase
target_link_libraries(SportsTicketing PRIVATE Qt6::Widgets)