#include <Main/SceneManager.hpp>
#include <Scenes/Scene.hpp>
#include <Scenes/MenuScene.hpp>

SceneManager::SceneManager(Window& w) : window(w) {
    this->currentScene = new MenuScene(this->window);
};

void SceneManager::updateCurrentScene() {
    this->currentScene->update();
}

void SceneManager::getCurrentEvent(sf::Event event) {
    this->currentScene->getEvent(event);
}