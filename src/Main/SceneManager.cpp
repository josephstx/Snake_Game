#include <Main/SceneManager.hpp>

SceneManager::SceneManager(Window& w) : window(w) {
    this->currentScene = new MenuScene(this->window);
};