cmake_minimum_required(VERSION 3.29)
project(CS225_Final_Project)

set(CMAKE_CXX_STANDARD 14)

include_directories(FinalProject)

add_executable(CS225_Final_Project
    FinalProject/ai.cpp
    FinalProject/cards.cpp
    FinalProject/cards.hpp
    FinalProject/deck.cpp
    FinalProject/deck.hpp
    FinalProject/global.cpp
    FinalProject/global.hpp
    FinalProject/hand.cpp
    FinalProject/hand.hpp
    FinalProject/human.cpp
    FinalProject/main.cpp
    FinalProject/player.cpp
    FinalProject/player.hpp
    FinalProject/table.cpp
    FinalProject/table.hpp)
