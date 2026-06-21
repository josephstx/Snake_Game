#include <SFML/Graphics.hpp>
#include <Main/Window.hpp>

Window::Window(unsigned int width, unsigned int height, std::string name) {
    this->window.create(sf::VideoMode({width, height}), name);
    this->window.setIcon(sf::Image("img/icon.png"));
}

void Window::begin() {
    this->window.clear();
}

void Window::end() {
    this->window.display();
}

bool Window::isOpen() const {
    return this->window.isOpen();
}

void Window::close() {
    this->window.close();
}

std::optional<sf::Event> Window::pollEvent() {
    return this->window.pollEvent();
}

void Window::drawPixel(float x, float y, sf::Color color, float size) {
    sf::RectangleShape pixel({size, size});
    pixel.setPosition({x, y});
    pixel.setFillColor(color);
    this->window.draw(pixel);
}