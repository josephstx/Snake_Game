#include <Main/Window.hpp>

Window::Window(unsigned int width, unsigned int height, std::string name) {
    this->window.create(sf::VideoMode({width, height}), name);
}