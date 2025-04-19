//
// Created by mikolaj on 4/19/25.
//

#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include <SFML/Graphics/RectangleShape.hpp>
#include <memory>
#include "Game.h"
#include "State.hpp"

class GamePlay : public Engine::State {
private:
    std::shared_ptr<Context> context;

    const int TILE_SIZE = 20;
    // Tile colors
    sf::Color lightGreen;
    sf::Color darkGreen;

    // Snake will be added here
public:
    GamePlay(std::shared_ptr<Context>& context);
    ~GamePlay();

    void init() override;
    void processInput() override;
    void update(sf::Time deltaTime) override;
    void draw() override;

    void pause() override;
    void start() override;
};



#endif //GAMEPLAY_H
