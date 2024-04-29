cmake_minimum_required(VERSION 3.27)
project(BugsLife)

set(CMAKE_CXX_STANDARD 17)

add_executable(BugsLife cppFiles/main.cpp
        cppFiles/Bug.cpp
        headerFiles/Bug.h
        cppFiles/Crawler.cpp
        headerFiles/Crawler.h
        cppFiles/Hopper.cpp
        headerFiles/Hopper.h
        cppFiles/Board.cpp
        headerFiles/Board.h
        cppFiles/BugFactory.cpp
        headerFiles/BugFactory.h
        cppFiles/Ant.cpp
        headerFiles/Ant.h
        cppFiles/GuiSimulation.cpp
        headerFiles/GuiSimulation.h
        cppFiles/SuperBug.cpp
        headerFiles/SuperBug.h
        headerFiles/BugShape.h)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML-2.6.1/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(C:/SFML-2.6.1/include)
target_link_libraries(BugsLife sfml-system sfml-window sfml-graphics sfml-audio)