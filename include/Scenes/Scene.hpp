#pragma once
#include <SFML/Graphics.hpp>

class Window;

enum class TypeScene {
    Menu,
    Game,
    Score,
    Options,
    Exit
};

class Scene {
    protected:
        Window& window;    

    public:
        Scene(Window& w);

        virtual void update() = 0;
        virtual void draw() = 0;
        virtual void getEvent(sf::Event) = 0;
};