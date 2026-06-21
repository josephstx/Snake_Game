#pragma once
#include <SFML/Graphics.hpp>

class Window {
    private:
        sf::RenderWindow window;

    public:
        Window(unsigned int width, unsigned int height, std::string name);

        // Window Main Functions
        void begin();
        void end();
        bool isOpen() const;
        void close();
        std::optional<sf::Event> pollEvent();

        // Rendering Functions
        void drawPixel(float x, float y, sf::Color color, float size);
};