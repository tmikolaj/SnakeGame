#include <ctime>
#include <cstdlib>
#include <SFML/Window/Event.hpp>
#include "../include/GamePlay.h"
#include "../include/GameOver.h"

GamePlay::GamePlay(std::shared_ptr<Context>& context) : context(context), snakeDirection({20, 0}), elapsedTime(sf::Time::Zero) {
    lightGreen.r = 170;  darkGreen.r = 162;
    lightGreen.g = 215;  darkGreen.g = 209;
    lightGreen.b = 81;   darkGreen.b = 73;
}
GamePlay::~GamePlay() {

}
void GamePlay::init() {
    // random seed for food position
    srand(time(nullptr));

    snake.init();

    const int rows = context->window->getSize().y / TILE_SIZE;
    const int cols = context->window->getSize().x / TILE_SIZE;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sf::Vector2f pos(j * 20, i * 20);

            // Snake init positions
            if (pos.y == 140 && (pos.x >= 100 && pos.x <= 160)) {
                continue;
            }

            freePos.push_back(pos);
        }
    }
    generateFood();
}
void GamePlay::processInput() {
    sf::Event evnt;
    while (context->window->pollEvent(evnt)) {

        if (evnt.type == sf::Event::Closed) {
            context->window->close();
        } else if (evnt.type == sf::Event::KeyPressed) {

            sf::Vector2f newDirection = snakeDirection;

            // Input check
            if (evnt.key.code == sf::Keyboard::Up || evnt.key.code == sf::Keyboard::W) {
                newDirection = {0, -20};
            }
            else if (evnt.key.code == sf::Keyboard::Down || evnt.key.code == sf::Keyboard::S) {
                newDirection = {0, 20};
            }
            else if (evnt.key.code == sf::Keyboard::Left || evnt.key.code == sf::Keyboard::A) {
                newDirection = {-20, 0};
            }
            else if (evnt.key.code == sf::Keyboard::Right || evnt.key.code == sf::Keyboard::D) {
                newDirection = {20, 0};
            }

            // Prevents snake changing direction by 180 degrees
            if (std::abs(snakeDirection.x) != std::abs(newDirection.x) || std::abs(snakeDirection.y) != std::abs(newDirection.y)) {
                snakeDirection = newDirection;
            }
        }
    }
}
void GamePlay::update(sf::Time deltaTime) {
    elapsedTime += deltaTime;

    if (elapsedTime.asSeconds() >= .1) {
        sf::Vector2f headPos = snake.getHeadPos();
        sf::Vector2u windowSize = context->window->getSize();

        // Game over checks
        if (snake.isSelfColliding()) {
            context->states->add(std::make_unique<GameOver>(context, "Self collided!"), true);
        } else if (headPos.x < 0 || headPos.y < 0 || headPos.x >= windowSize.x || headPos.y >= windowSize.y) {
            // Game over screen
            context->states->add(std::make_unique<GameOver>(context, "Out of board!"), true);
        }

        if (snake.isOn(food)) {
            snake.grow(snakeDirection);
            generateFood();
        } else {
            snake.move(snakeDirection);
        }

        elapsedTime = sf::Time::Zero;
    }
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
    context->window->draw(snake);
    context->window->draw(food);
    context->window->display();
}
void GamePlay::pause() {

}
void GamePlay::start() {

}
void GamePlay::generateFood() {
    // Update free positions before generating food
    freePos.clear();

    const int rows = context->window->getSize().y / TILE_SIZE;
    const int cols = context->window->getSize().x / TILE_SIZE;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sf::Vector2f pos(j * TILE_SIZE, i * TILE_SIZE);

            bool isOccupied = false;
            for (const auto& piece : snake.getBody()) {
                if (piece.getPosition() == pos) {
                    isOccupied = true;
                    break;
                }
            }

            if (!isOccupied) {
                freePos.push_back(pos);
            }
        }
    }
    if (freePos.empty()) {
        context->states->add(std::make_unique<GameOver>(context, "You won! Congratulations!"), true);
    }
    // Random pos for food
    int random = rand() % freePos.size();

    // Top left of the tile
    sf::Vector2f basePos = freePos[random];

    food.setSize(sf::Vector2f(TILE_SIZE - 5, TILE_SIZE - 5));
    // For centering food inside the tile
    float offset = (TILE_SIZE - food.getSize().x) / 2.f;

    food.setPosition(basePos.x + offset, basePos.y + offset);
    food.setFillColor(sf::Color(200, 50, 50));
    food.setOutlineThickness(1);
    food.setOutlineColor(sf::Color::Black);
}