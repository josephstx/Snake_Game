#pragma once
#include <SFML/Graphics.hpp>
#include <Main/Window.hpp>
#include <Main/InputStream.hpp>

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

        virtual void update();
        virtual void draw();
        virtual void getEvent(std::optional<sf::Event>);
};