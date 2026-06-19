#pragma once

#include <SFML/Graphics.hpp>

class Draw {
    private:
        //

    public:
        static void drawPixel(sf::RenderWindow* ptr_window, sf::Vector2f pos, sf::Color color, float size);
        static void drawMtx(sf::RenderWindow* ptr_window, std::vector<std::string> mtx, sf::Vector2f pos, sf::Color color, float size);
        static void drawText(sf::RenderWindow* ptr_window, std::string text, sf::Vector2f pos, sf::Color color, float size);
};