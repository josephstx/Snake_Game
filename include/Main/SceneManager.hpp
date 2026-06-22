#pragma once
#include <Main/Window.hpp>
#include <Scenes/Scene.hpp>
#include <Scenes/MenuScene.hpp>

class SceneManager {
    private:
        Window& window;
        Scene* currentScene = nullptr;
    
    public:
        SceneManager(Window& w);
};