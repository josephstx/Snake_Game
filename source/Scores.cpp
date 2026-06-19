#include <SFML/Graphics.hpp>
#include <Scores.hpp>
#include <Type.hpp>
#include <Draw.hpp>
#include <Sound.hpp>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

Scores::Scores(sf::RenderWindow* ptr_window, Scenes* ptr_current_scene) {
    this-> ptr_window = ptr_window;
    this-> ptr_current_scene = ptr_current_scene;
}

std::vector<ScoreItem> Scores::getScoreBoard() {
    score_board.clear();

    std::ifstream file("../user/user.dat");

    int day, month, score, time;

    while(file >> day >> month >> score >> time) {
        ScoreItem newScores = {day, month, score, time};
        score_board.push_back(newScores);
    }

    sort(score_board.rbegin(), score_board.rend());

    return score_board;
}

void Scores::draw() {
    Draw::drawText(ptr_window, "BEST SCORES", {8.f, 5.f}, sf::Color::White, 10.f);

    Draw::drawText(ptr_window, "DATE", {20.f, 30.f}, sf::Color::White, 5.f);
    Draw::drawText(ptr_window, "SCORE", {65.f, 30.f}, sf::Color::White, 5.f);
    Draw::drawText(ptr_window, "TIME", {115.f, 30.f}, sf::Color::White, 5.f);

    for(int i = 0; i < std::min(int(score_board.size()), 5); i++) {
        Draw::drawText(ptr_window, std::to_string(i + 1) + ".", {7.f, float(40 + (14 * i))}, sf::Color::White, 5.f);

        std::string day = std::to_string(score_board[i].day);
        std::string month = std::to_string(score_board[i].month);
        std::string score = std::to_string(score_board[i].score);
        std::string time = std::to_string(score_board[i].time);
        std::string date = day + "." + month;

        for(auto &c : day) if(c == '0') c = 'O';
        for(auto &c : month) if(c == '0') c = 'O';
        for(auto &c : score) if(c == '0') c = 'O';
        for(auto &c : time) if(c == '0') c = 'O';
        for(auto &c : date) if(c == '0') c = 'O';

        Draw::drawText(ptr_window, date, {20.f, float(40 + (14 * i))}, sf::Color::White, 5.f);
        Draw::drawText(ptr_window, score, {65.f, float(40 + (14 * i))}, sf::Color::White, 5.f);
        Draw::drawText(ptr_window, time, {115.f, float(40 + (14 * i))}, sf::Color::White, 5.f);
    }

    Draw::drawText(ptr_window, "PRESS ESC TO GO BACK TO THE MENU", {5.f, 190.f}, sf::Color::White, 3.f);
}

void Scores::getEvent(std::optional<sf::Event> event) {
    if(event-> is<sf::Event::KeyPressed>()) {
        auto key = event-> getIf<sf::Event::KeyPressed>();

        if(key-> code == sf::Keyboard::Key::Escape) {
            Sound::start-> play();
            *ptr_current_scene = Scenes::Menu;
        }
    }
}

void Scores::update() {
    score_board = Scores::getScoreBoard();
    Scores::draw();
}