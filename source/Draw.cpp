#include <SFML/Graphics.hpp>
#include <Draw.hpp>
#include <Font.hpp>
#include <vector>
#include <string>

void Draw::drawPixel(sf::RenderWindow* ptr_window, sf::Vector2f pos, sf::Color color, float size) {
    sf::RectangleShape pixel({size, size});
    pixel.setFillColor(color);
    pixel.setPosition({pos.x * size, pos.y * size});

    ptr_window-> draw(pixel);
}

void Draw::drawMtx(sf::RenderWindow* ptr_window, std::vector<std::string> mtx, sf::Vector2f pos, sf::Color color, float size) {
    for(int y = 0; y < mtx.size(); y++) {
        for(int x = 0; x < mtx[y].size(); x++) {
            if(mtx[y][x] == '1') {
                Draw::drawPixel(ptr_window, {pos.x + float(x), pos.y + float(y)}, color, size);
            }
        }
    }
}

void Draw::drawText(sf::RenderWindow* ptr_window, std::string text, sf::Vector2f pos, sf::Color color, float size) {
    std::vector<std::string> mtx = Font::mtxText(text);
    Draw::drawMtx(ptr_window, mtx, pos, color, size);
}