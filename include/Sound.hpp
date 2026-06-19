#pragma once

#include <SFML/Audio.hpp>
#include <Type.hpp>

class Sound {
    public:
        static sf::SoundBuffer eatBuff;
        static std::optional<sf::Sound> eat;

        static sf::SoundBuffer menuBuff;
        static std::optional<sf::Sound> menu;

        static sf::SoundBuffer startBuff;
        static std::optional<sf::Sound> start;

        static sf::SoundBuffer game_overBuff;
        static std::optional<sf::Sound> game_over;
        
        static void init();
        static void playSound(Sounds sound);
};