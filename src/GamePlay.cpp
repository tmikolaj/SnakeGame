//
// Created by mikolaj on 4/19/25.
//

#include <SFML/Window/Event.hpp>
#include "../include/GamePlay.h"

GamePlay::GamePlay(std::shared_ptr<Context>& context) : context(context) {
    lightGreen.r = 170;  darkGreen.r = 162;
    lightGreen.g = 215;  darkGreen.g = 209;
    lightGreen.b = 81;   darkGreen.b = 73;
}
GamePlay::~GamePlay() {

}
void GamePlay::init() {
    // Grid position to pixels
    sf::Vector2f foodPos(foodGridPos.x * TILE_SIZE, foodGridPos.y * TILE_SIZE);

    food.setSize(sf::Vector2f(TILE_SIZE, TILE_SIZE));
    food.setPosition(foodPos);
    food.setFillColor(sf::Color(200, 50, 50));
    food.setOutlineThickness(1);
    food.setOutlineColor(sf::Color::Black);
}
void GamePlay::processInput() {
    sf::Event evnt;
    while (context->window->pollEvent(evnt)) {
        if (evnt.type == sf::Event::Closed) {
            context->window->close();
        }
    }
}
void GamePlay::update(sf::Time deltaTime) {

}
void GamePlay::draw() {
    context->window->clear();

    const int rows = context->window->getSize().y / TILE_SIZE;
    const int cols = context->window->getSize().x / TILE_SIZE;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sf::RectangleShape tile(sf::Vector2f(TILE_SIZE, TILE_SIZE));
            tile.setPosition(j * TILE_SIZE, i * TILE_SIZE);

            bool isLightGreen = (i + j) % 2 == 0;
            tile.setFillColor(isLightGreen ? lightGreen : darkGreen);

            context->window->draw(tile);
        }
    }

    context->window->display();
}
void GamePlay::pause() {

}
void GamePlay::start() {

}