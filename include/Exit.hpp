#pragma once

#include <SFML/Graphics.hpp>
#include <Type.hpp>
#include <vector>

class Exit {
    private:
        sf::RenderWindow* ptr_window;
        Scenes* ptr_current_scene;
        int current_option;
        std::vector<Scenes> options;

    public:
        Exit(sf::RenderWindow* ptr_window, Scenes* ptr_current_scene);

        void update();
        void draw();
        sf::Color setColorOption(int opt);
        void getEvent(std::optional<sf::Event> event);
};