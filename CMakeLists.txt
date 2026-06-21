cmake_minimum_required(VERSION 3.20)

project(Snake)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

add_executable(Snake
    src/main.cpp
    src/Main/Game.cpp
    src/Main/Window.cpp
    src/Main/InputStream.cpp
)

find_package(SFML 3 COMPONENTS Graphics Window System Audio REQUIRED)

target_link_libraries(Snake
    SFML::Graphics
    SFML::Window
    SFML::System
    SFML::Audio
)
