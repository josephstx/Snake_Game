#include <SFML/Graphics.hpp>
#include <Exit.hpp>
#include <Type.hpp>
#include <Font.hpp>
#include <Draw.hpp>
#include <Sound.hpp>

Exit::Exit(sf::RenderWindow* ptr_window, Scenes* ptr_current_scene) {
    this-> ptr_window = ptr_window;
    this-> ptr_current_scene = ptr_current_scene;
    current_option = 0;
    options = {Scenes::Menu, Scenes::Exit};
}

sf::Color Exit::setColorOption(int opt) {
    if(opt == current_option) return sf::Color::Yellow;
    else return sf::Color::White;
}

void Exit::draw() {
    Draw::drawText(ptr_window, "LEAVE GAME?", {10.f, 13.f}, sf::Color::White, 10.f);
    Draw::drawText(ptr_window, "YES", {15.f, 35.f}, Exit::setColorOption(0), 10.f);
    Draw::drawText(ptr_window, "NO", {52.f, 35.f}, Exit::setColorOption(1), 10.f);
}

void Exit::getEvent(std::optional<sf::Event> event) {
    if(event-> is<sf::Event::KeyPressed>()) {
        auto key = event-> getIf<sf::Event::KeyPressed>();

        switch(key-> code) {
            case sf::Keyboard::Key::Left:
                current_option = (current_option + 1) % 2;
                Sound::playSound(Sounds::Menu);
                break;

            case sf::Keyboard::Key::Right:
                current_option = (current_option + 1) % 2;
                Sound::playSound(Sounds::Menu);
                break;

            case sf::Keyboard::Key::Enter:
                if(current_option == 0) ptr_window-> close();
                else if(current_option == 1) *ptr_current_scene = Scenes::Menu;
                Sound::playSound(Sounds::Start);
                break;
                
            default:
                break;
        }
    }
}

void Exit::update() {
    Exit::draw();
}