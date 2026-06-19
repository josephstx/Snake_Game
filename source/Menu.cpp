#include <SFML/Graphics.hpp>
#include <Menu.hpp>
#include <Type.hpp>
#include <Font.hpp>
#include <Draw.hpp>
#include <Sound.hpp>

Menu::Menu(sf::RenderWindow* ptr_window, Scenes* ptr_current_scene) {
    this-> ptr_window = ptr_window;
    this-> ptr_current_scene = ptr_current_scene;
    current_option = 0;
    options = {Scenes::Game, Scenes::Scores, Scenes::Exit};
}

sf::Color Menu::setColorOption(int opt) {
    if(opt == current_option) return sf::Color::Yellow;
    else return sf::Color::White;
}

void Menu::draw() {
    Draw::drawText(ptr_window, "SNAKE", {11.f, 6.f}, sf::Color::White, 15.f);
    Draw::drawText(ptr_window, "PLAY", {28.f, 25.f}, Menu::setColorOption(0), 10.f);
    Draw::drawText(ptr_window, "SCORES", {21.f, 37.f}, Menu::setColorOption(1), 10.f);
    Draw::drawText(ptr_window, "EXIT", {28.f, 49.f}, Menu::setColorOption(2), 10.f);
    Draw::drawText(ptr_window, "V1.O BY JOSEPHSTX", {5.f, 190.f}, sf::Color::White, 3.f);
}

void Menu::getEvent(std::optional<sf::Event> event) {
    if(event-> is<sf::Event::KeyPressed>()) {
        auto key = event-> getIf<sf::Event::KeyPressed>();

        switch(key-> code) {
            case sf::Keyboard::Key::Up:
                current_option = (current_option + 2) % 3;
                Sound::playSound(Sounds::Menu);
                break;

            case sf::Keyboard::Key::Down:
                current_option = (current_option + 1) % 3;
                Sound::playSound(Sounds::Menu);
                break;

            case sf::Keyboard::Key::Enter:
                *ptr_current_scene = options[current_option];
                Sound::playSound(Sounds::Start);
                break;
                
            default:
                break;
        }
    }
}

void Menu::update() {
    Menu::draw();
}