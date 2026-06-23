#pragma once
#include <vector>
#include <Scenes/Scene.hpp>

class MenuScene : public Scene {
    private:
        int iCurrentOption;
        int jCurrentOption;
        std::vector<std::vector<TypeScene>> options;

    public:
        MenuScene(Window& w);

        void update() override;
        void draw() override;
        void getEvent(sf::Event) override;
};