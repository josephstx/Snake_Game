#include <Scenes/Scene.hpp>
#include <Scenes/MenuScene.hpp>

MenuScene::MenuScene(Window& w) : Scene::Scene(w) {
    this->iCurrentOption = 0;
    this->jCurrentOption = 0;

    this->options = {
        {TypeScene::Game, TypeScene::Score}, 
        {TypeScene::Options, TypeScene::Exit}
    };
}