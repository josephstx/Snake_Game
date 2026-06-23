#include <Main/Game.hpp>

Game::Game() : window(800, 600, "Snake"), sceneManager(window), input(window, sceneManager) {}

void Game::run() {
    while(this->window.isOpen()) {
        input.startEvent();

        window.begin();
        sceneManager.updateCurrentScene();
        window.end();
    }
}