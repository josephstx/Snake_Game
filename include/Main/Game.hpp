#pragma once
#include <Main/Window.hpp>
#include <Main/InputStream.hpp>

class Game {
    private:
        Window window;
        InputStream input;

    public:
        Game();

        void run();
};