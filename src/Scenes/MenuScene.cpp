#include <Main/Window.hpp>
#include <Scenes/MenuScene.hpp>

MenuScene::MenuScene(Window& w) : Scene(w) {
    this->iCurrentOption = 0;
    this->jCurrentOption = 0;

    this->options = {
        {TypeScene::Game, TypeScene::Score}, 
        {TypeScene::Options, TypeScene::Exit}
    };
}

void MenuScene::getEvent(sf::Event event) {}

void MenuScene::draw() {
    this->window.drawPixel(30.f, 30.f, sf::Color::Red, 20.f);
}

void MenuScene::update() {
    this->draw();
}