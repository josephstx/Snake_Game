#pragma once
#include <SFML/Graphics.hpp>
#include <Main/Window.hpp>

class InputStream {
    private:
        Window& window;

    public:
        InputStream(Window& w);

        void startEvent();
};