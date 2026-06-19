#pragma once

#include <SFML/Graphics.hpp>
#include <Type.hpp>
#include <Menu.hpp>
#include <Game.hpp>
#include <Scores.hpp>
#include <Exit.hpp>

class Program {
    private:
        // Window
        sf::RenderWindow window;
        Scenes current_scene;

        // Scene Objects:
        Menu menuProgram = Menu(&window, &current_scene);
        Game gameProgram = Game(&window, &current_scene);
        Scores scoresProgram = Scores(&window, &current_scene);
        Exit exitProgram = Exit(&window, &current_scene);

    public:
        Program();

        void gameLoop();
};