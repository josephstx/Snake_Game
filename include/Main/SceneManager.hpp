#pragma once
#include <SFML/Graphics.hpp>

class Window;
class Scene;

class SceneManager {
    private:
        Window& window;
        Scene* currentScene = nullptr;
    
    public:
        SceneManager(Window& w);

        void updateCurrentScene();
        void getCurrentEvent(sf::Event event);
};