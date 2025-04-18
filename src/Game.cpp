//
// Created by mikolaj on 4/17/25.
//

#include "../include/Game.h"
#include "../include/MainMenu.h"

Game::Game() : context(std::make_shared<Context>()) {
    context->window->create(sf::VideoMode(200,200), "SFML works", sf::Style::Close);
    context->states->add(std::make_unique<MainMenu>(context));
}

Game::~Game() {

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
