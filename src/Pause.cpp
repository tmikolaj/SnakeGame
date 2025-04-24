#include <SFML/Window/Event.hpp>
#include "../include/Pause.h"
#include "../include/GamePlay.h""

Pause::Pause(std::shared_ptr<Context>& context) : context(context) {

}
Pause::~Pause() {

}
void Pause::init() {
    // Title init
    title.setFont(context->assets->getFont(MAIN_FONT));
    title.setString("Game Paused!");
    title.setOrigin(title.getLocalBounds().width/2,title.getLocalBounds().height/2);
    title.setPosition(context->window->getSize().x / 2, context->window->getSize().y / 2 - 150);
}
void Pause::processInput() {
    sf::Event evnt;
    while (context->window->pollEvent(evnt)) {
        if (evnt.type == sf::Event::Closed) {
            context->window->close();
        }
        else if (evnt.type == sf::Event::KeyPressed) {
            if (evnt.key.code == sf::Keyboard::Escape) {
                context->states->popCurrent();
            }
        }
    }
}
void Pause::update(sf::Time deltaTime) {

}
void Pause::draw() {
    context->window->draw(title);
    context->window->display();
}
