#include <SFML/Audio.hpp>
#include <Sound.hpp>
#include <Type.hpp>
#include <iostream>

sf::SoundBuffer Sound::eatBuff;
std::optional<sf::Sound> Sound::eat;

sf::SoundBuffer Sound::menuBuff;
std::optional<sf::Sound> Sound::menu;

sf::SoundBuffer Sound::startBuff;
std::optional<sf::Sound> Sound::start;

sf::SoundBuffer Sound::game_overBuff;
std::optional<sf::Sound> Sound::game_over;
        

void Sound::init() {
    if(!eatBuff.loadFromFile("../audio/eat.wav")) std::cerr << "Error loading /audio/eat.wav\n";
    eat.emplace(eatBuff);

    if(!menuBuff.loadFromFile("../audio/menu.wav")) std::cerr << "Error loading /audio/menu.wav\n";
    menu.emplace(menuBuff);
    
    if(!startBuff.loadFromFile("../audio/start.wav")) std::cerr << "Error loading /audio/start.wav\n";
    start.emplace(startBuff);

    if(!game_overBuff.loadFromFile("../audio/game_over.wav")) std::cerr << "Error loading /audio/game_over.wav\n";
    game_over.emplace(game_overBuff);
}

void Sound::playSound(Sounds sound) {
    switch(sound) {
        case Sounds::Eat:
            eat-> play();
            break;

        case Sounds::Menu:
            menu-> play();
            break;

        case Sounds::Start:
            start-> play();
            break;

        case Sounds::GameOver:
            game_over-> play();
            break;

        default:
            break;
    }
}