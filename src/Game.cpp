//
// Created by mikolaj on 4/17/25.
//

#include <SFML/Window/Event.hpp>
#include "../include/Game.h"

Game::Game() {
    context->window->create(sf::VideoMode(200,200), "SFML works", sf::Style::Close);
    // Add first state to states here
    // will be implemented soon
}

Game::~Game() {

}

void Game::run() {
    while (context->window->isOpen()) {
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
