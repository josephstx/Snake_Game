#pragma once
#include <SFML/Graphics.hpp>
#include <Main/Window.hpp>
#include <Main/SceneManager.hpp>

class InputStream {
    private:
        Window& window;
        SceneManager& sceneManager;

    public:
        InputStream(Window& w, SceneManager& s);

        void startEvent();
};