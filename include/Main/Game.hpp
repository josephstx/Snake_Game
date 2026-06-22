#pragma once
#include <Main/Window.hpp>
#include <Main/InputStream.hpp>
#include <SceneManager.hpp>

class Game {
    private:
        Window window;
        SceneManager sceneManager;
        InputStream input;

    public:
        Game();

        void run();
};