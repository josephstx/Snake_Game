#include <Main/InputStream.hpp>
#include <Main/SceneManager.hpp>
#include <Main/Window.hpp>

InputStream::InputStream(Window& w, SceneManager& s) : window(w), sceneManager(s) {}

void InputStream::startEvent() {
    while(const std::optional event = this->window.pollEvent()) {
        
        if(event->is<sf::Event::Closed>()) this->window.close();
    }
}