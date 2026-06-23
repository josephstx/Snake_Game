#pragma once

class Window;
class SceneManager;

class InputStream {
    private:
        Window& window;
        SceneManager& sceneManager;

    public:
        InputStream(Window& w, SceneManager& s);

        void startEvent();
};