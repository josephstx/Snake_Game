#include <Scenes/Scene.hpp>

Scene::Scene(Window& w) : window(w) {}

void Scene::update() {}
void Scene::draw() {}
void Scene::getEvent(std::optional<sf::Event>) {}