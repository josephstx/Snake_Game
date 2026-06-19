cmake_minimum_required(VERSION 3.20)

project(Snake)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

add_executable(Snake
    source/main.cpp
    source/Program.cpp
    source/Menu.cpp
    source/Game.cpp
    source/Scores.cpp
    source/Exit.cpp
    source/Font.cpp
    source/Draw.cpp
    source/RandNum.cpp
    source/Sound.cpp
)

find_package(SFML 3 COMPONENTS Graphics Window System Audio REQUIRED)

target_link_libraries(Snake
    SFML::Graphics
    SFML::Window
    SFML::System
    SFML::Audio
)
