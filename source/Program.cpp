#include <SFML/Graphics.hpp>
#include <Program.hpp>
#include <Type.hpp>
#include <Sound.hpp>

Program::Program() {
    window.create(sf::VideoMode({800, 600}), "Snake");
    sf::Image icon("../images/icon.png");
    window.setIcon(icon);
    current_scene = Scenes::Menu;
}

void Program::gameLoop() {
    Sound::init();
    while(window.isOpen()) {
        while(const std::optional event = window.pollEvent()) {
            switch(current_scene) {
                case Scenes::Menu:
                    menuProgram.getEvent(event);
                    break;

                case Scenes::Game:
                    gameProgram.getEvent(event);
                    break;

                case Scenes::Scores:
                    scoresProgram.getEvent(event);
                    break;

                case Scenes::Exit:
                    exitProgram.getEvent(event);
                    break;

                default:
                    break;
            }

            if(event-> is<sf::Event::Closed>()) window.close();
        }

        window.clear();

        switch(current_scene) {
            case Scenes::Menu:
                menuProgram.update();
                break;

            case Scenes::Game:
                gameProgram.update();  
                break;         

            case Scenes::Scores:
                scoresProgram.update();    
                break;

            case Scenes::Exit:
                exitProgram.update();
                break;

            default:
                break;
        }

        window.display();
    }
}