#pragma once

#include <SFML/Graphics.hpp>
#include <Type.hpp>
#include <vector>

struct ScoreItem {
    int day, month, score, time;

    bool operator <(const ScoreItem &other) const {
        if(score == other.score) return time < other.time;
        return score < other.score;
    }
};

class Scores {
    private:
        sf::RenderWindow* ptr_window;
        Scenes* ptr_current_scene;

        std::vector<ScoreItem> score_board;

    public:
        Scores(sf::RenderWindow* ptr_window, Scenes* ptr_current_scene);

        void update();
        void draw();
        void getEvent(std::optional<sf::Event> event);
        std::vector<ScoreItem> getScoreBoard();
};