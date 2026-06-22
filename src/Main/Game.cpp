#include <Main/Game.hpp>

Game::Game() : window(800, 600, "Snake"), sceneManager(window), input(window, sceneManager) {}

void Game::run() {
    while(this->window.isOpen()) {
        input.startEvent();

        window.begin();
        window.drawPixel(10.f, 10.f, sf::Color::Red, 20.f);
        window.end();
    }
}