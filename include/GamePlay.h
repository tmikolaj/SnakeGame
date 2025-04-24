#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <memory>
#include "Game.h"
#include "State.hpp"
#include "Snake.h"

class GamePlay : public Engine::State {
private:
    std::shared_ptr<Context> context;

    const int TILE_SIZE = 20;
    // Tile colors
    sf::Color lightGreen;
    sf::Color darkGreen;

    // Food
    sf::RectangleShape food;
    sf::Vector2i foodGridPos;
    // Will store the free positions (little optimization for
    // generating the food)
    std::vector<sf::Vector2f> freePos;

    // Snake
    Snake snake;
    sf::Vector2f snakeDirection;
    sf::Time elapsedTime;

    // Points
    sf::Text pointsText;
    int score;
public:
    GamePlay(std::shared_ptr<Context>& context);
    ~GamePlay();

    void init() override;
    void processInput() override;
    void update(sf::Time deltaTime) override;
    void draw() override;

    void pause() override;
    void start() override;

    void generateFood();
};



#endif //GAMEPLAY_H
