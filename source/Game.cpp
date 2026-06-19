#include <SFML/Graphics.hpp>
#include <Game.hpp>
#include <Draw.hpp>
#include <Type.hpp>
#include <RandNum.hpp>
#include <Sound.hpp>
#include <deque>
#include <string>
#include <fstream>

Game::Game(sf::RenderWindow* ptr_window, Scenes* current_scene) {
    this-> ptr_window = ptr_window;
    this-> ptr_current_scene = current_scene;
    
    points = 0;
    isGameOver = false;
    isStart = false;
    isSave = false;
    
    dirMap = {
        {Dirs::Up, sf::Vector2i(0, 1)},
        {Dirs::Down, sf::Vector2i(0, -1)},
        {Dirs::Left, sf::Vector2i(1, 0)},
        {Dirs::Right, sf::Vector2i(-1, 0)}
    };

    dirDir = {
        {1, {Dirs::Right, Dirs::Down}},
        {2, {Dirs::Left, Dirs::Down}},
        {3, {Dirs::Right, Dirs::Up}},
        {4, {Dirs::Left, Dirs::Up}}
    };

    Game::respawnSnake();
    Game::respawnFood();
}

void Game::respawnSnake() {
    int headX = RandNum::getRandInt(2, 37);
    int headY = RandNum::getRandInt(2, 27);
    int halfP = RandNum::getRandInt(1, 2);
    int screenPos = 0;

    if(headX <= 20 && headY <= 15) screenPos = 1; 
    else if(headX > 20 && headY <= 15) screenPos = 2; 
    else if(headX <= 20 && headY > 15) screenPos = 3;  
    else if(headX > 20 && headY > 15) screenPos = 4;

    curr_dir = (halfP == 1 ? dirDir[screenPos].first : dirDir[screenPos].second);

    body.push_back(sf::Vector2u(headX, headY));
    body.push_back(sf::Vector2u(headX - dirMap[dir].x, headY - dirMap[dir].y));
    body.push_back(sf::Vector2u(headX - (2 * dirMap[dir].x), headY - (2 * dirMap[dir].y)));
}

void Game::respawnFood() {
    while(true) {
        bool e = true;
        sf::Vector2u new_pos(RandNum::getRandInt(0, 39), RandNum::getRandInt(0, 29));
        for(auto shape : body) if(shape.x == new_pos.x && shape.y == new_pos.y) e = false;
        
        if(e) {
            food_position = new_pos;
            break;
        }
    }
}

void Game::setDir(Dirs new_dir) {
    if(dirMap[dir].x != dirMap[new_dir].x * -1 || dirMap[dir].y != dirMap[new_dir].y * -1) {
        curr_dir = new_dir;
    }    
}

void Game::getEvent(std::optional<sf::Event> event) {
    if(event-> is<sf::Event::KeyPressed>()) {
        auto key = event-> getIf<sf::Event::KeyPressed>();

        if(!isGameOver) {
            switch(key-> code) {
                case sf::Keyboard::Key::Up:
                    Game::setDir(Dirs::Up);
                    break;

                case sf::Keyboard::Key::Down:
                    Game::setDir(Dirs::Down);
                    break;

                case sf::Keyboard::Key::Left:
                    Game::setDir(Dirs::Left);
                    break;
                    
                case sf::Keyboard::Key::Right:
                    Game::setDir(Dirs::Right);
                    break;

                default:
                    break;
            }
        }
        else {
            switch(key-> code) {
                case sf::Keyboard::Key::Enter:
                    Game::retry();
                    break;

                case sf::Keyboard::Key::Escape:
                    *ptr_current_scene = Scenes::Menu;
                    Game::retry();
                    break;

                default: 
                    break;
            }
        }
    }
}

void Game::retry() {
    body.clear();
    points = 0;
    isGameOver = false;
    isStart = false;
    isSave = false;
    respawnSnake();
    respawnFood();
    Sound::playSound(Sounds::Start);
}

void Game::moveSnake() {
    sf::Vector2u head = body.front();
    sf::Vector2u new_head(head.x - dirMap[dir].x, head.y - dirMap[dir].y);

    if(new_head.x < 0 || new_head.x >= 40 || new_head.y < 0 || new_head.y >= 30) {
        if(!isGameOver) Sound::playSound(Sounds::GameOver);
        isGameOver = true;
    }

    for(auto shape : body) {
        if(shape == new_head) {
            if(!isGameOver) Sound::playSound(Sounds::GameOver);
            isGameOver = true;
        } 
    }

    if(isGameOver) return;

    body.push_front(new_head);

    if(new_head != food_position) {
        body.pop_back();
    }
    else {
        Game::respawnFood();
        Sound::playSound(Sounds::Eat);
        points++;
        end_time -= 0.0005f;
    }
}

void Game::drawSnake() {
    for(auto shape : body) {
        Draw::drawPixel(ptr_window, {float(shape.x), float(shape.y)}, sf::Color::Green, 20.f);
    }
}

void Game::drawFood() {
    Draw::drawPixel(ptr_window, {float(food_position.x), float(food_position.y)}, sf::Color::Red, 20.f);
}

void Game::drawPoints() {
    std::string str_points = std::to_string(points);
    std::string empty = "";

    for(char &c : str_points) if(c == '0') c = 'O';
    for(int i = 0; i < 4 - str_points.size(); i++) empty += "0";
    str_points = empty + str_points;

    Draw::drawText(ptr_window, str_points, {55.f, 53.f}, sf::Color::White, 10.f);
}

void Game::draw() {
    Game::drawSnake();
    Game::drawFood();
    Game::drawPoints();
}

void Game::GameOverScene() {
    Draw::drawText(ptr_window, "GAME OVER", {2.f, 53.f}, sf::Color::White, 10.f);
    Draw::drawText(ptr_window, "PRESS ENTER TO RETRY", {10.f, 10.f}, sf::Color::White, 4.f);
    Draw::drawText(ptr_window, "OR ESC TO BACK TO THE MENU", {10.f, 20.f}, sf::Color::White, 4.f);

    if(!isSave) {
        isSave = true;
        Game::saveGame();
    }
}

void Game::saveGame() {
    int time = int(game_clock.restart().asSeconds());
    int day;
    int month;

    std::string date = __DATE__;
    std::string str_month = date.substr(0, 3);

    if(str_month == "Jan") month = 1;
    if(str_month == "Feb") month = 2;
    if(str_month == "Mar") month = 3;
    if(str_month == "Apr") month = 4;
    if(str_month == "May") month = 5;
    if(str_month == "Jun") month = 6;
    if(str_month == "Jul") month = 7;
    if(str_month == "Aug") month = 8;
    if(str_month == "Sep") month = 9;
    if(str_month == "Oct") month = 10;
    if(str_month == "Nov") month = 11;
    if(str_month == "Dec") month = 12;

    std::string str_day = date.substr(4, 2);
    if(str_day[1] == ' ') str_day = str_day.substr(0, 1);
    day = std::stoi(str_day);

    std::ofstream file("../user/user.dat", std::ios::app);

    if(file.is_open()) {
        file << '\n' << day << " " << month << " " << points << " " << time;
    }
}

void Game::update() {
    Game::draw();
    
    if(isGameOver) Game::GameOverScene();
    
    if(!isStart) {
        isStart = true;
        game_clock.restart();
    }

    else if(clock.getElapsedTime().asSeconds() >= end_time) {
        dir = curr_dir;
        Game::moveSnake();
        clock.restart();
    }
}