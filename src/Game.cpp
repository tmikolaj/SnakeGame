//
// Created by mikolaj on 4/17/25.
//

#include <SFML/Window/Event.hpp>
#include "../include/Game.h"

Game::Game() : context(std::make_shared<Context>()) {
    context->window->create(sf::VideoMode(200,200), "SFML works", sf::Style::Close);
    // Add first state to states here
    // will be implemented soon
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

            // Not yet working
            // context->states->processState();
            // context->states->getCurrentState()->processInput();
            // context->states->getCurrentState()->update(TIME_PER_FRAME);
            // context->states->getCurrentState()->draw();

            sf::Event evnt;
            while (context->window->pollEvent(evnt)) {
                if (evnt.type == sf::Event::Closed) {
                    context->window->close();
                }
            }
            // Clear the window with black color
            context->window->clear(sf::Color::Black);

            // Display the current frame
            context->window->display();
        }
    }
}
