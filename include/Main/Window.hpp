#pragma once
#include <SFML/Graphics.hpp>

class Window {
    private:
        sf::RenderWindow window;

    public:
        Window(unsigned int width, unsigned int height, std::string name);
};