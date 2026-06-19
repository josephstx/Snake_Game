#pragma once

#include <SFML/Graphics.hpp>
#include <Type.hpp>
#include <deque>
#include <map>

class Game {
    private:
        // Main
        sf::RenderWindow* ptr_window;
        Scenes* ptr_current_scene;
        sf::Clock clock;
        sf::Clock game_clock;
        float end_time = 0.2f;

        // Snake
        std::deque<sf::Vector2u> body;
        Dirs dir;
        Dirs curr_dir;
        bool isGameOver;
        bool isStart;
        bool isSave;

        // Food
        sf::Vector2u food_position;

        // Points & Dics
        int points;
        std::map<Dirs, sf::Vector2i> dirMap;
        std::map<int, std::pair<Dirs, Dirs>> dirDir;

    public:
        Game(sf::RenderWindow* ptr_window, Scenes* ptr_current_scene);

        void update();
        void draw();
        void getEvent(std::optional<sf::Event> event);
        void GameOverScene();
        void drawPoints();
        void retry();
        void saveGame();

        // Snake
        void respawnSnake();
        void moveSnake();
        void drawSnake();
        void setDir(Dirs dir);

        // Food
        void respawnFood();
        void drawFood();
};