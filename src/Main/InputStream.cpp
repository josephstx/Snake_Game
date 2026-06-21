#include <Main/InputStream.hpp>

InputStream::InputStream(Window& w) : window(w) {}

void InputStream::startEvent() {
    while(const std::optional event = this->window.pollEvent()) {
        
        if(event->is<sf::Event::Closed>()) this->window.close();
    }
}