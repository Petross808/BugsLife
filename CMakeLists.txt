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
        headerFiles/BugFactory.h)
