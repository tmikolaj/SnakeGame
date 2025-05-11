#include "../include/Game.h"
#include "../include/MainMenu.h"

Game::Game() : context(std::make_shared<Context>()) {
    context->window->create(sf::VideoMode(640,360), "sfml snake game", sf::Style::Close);
    context->states->add(std::make_unique<MainMenu>(context));
}
void Game::run() {
    sf::Clock clock;
    sf::Time timeSinceLastFrame = sf::Time::Zero;

    while (context->window->isOpen()) {
        timeSinceLastFrame += clock.restart();

        while (timeSinceLastFrame > TIME_PER_FRAME) {
            timeSinceLastFrame -= TIME_PER_FRAME;

            context->states->processState();
            context->states->getCurrentState()->processInput();
            context->states->getCurrentState()->update(TIME_PER_FRAME);
            context->states->getCurrentState()->draw();
        }
    }
}
