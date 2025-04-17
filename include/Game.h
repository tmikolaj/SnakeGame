//
// Created by mikolaj on 4/17/25.
//

#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <memory>
#include "StateManager.h"

struct context {
    std::unique_ptr<Engine::StateManager> states;
    std::unique_ptr<sf::RenderWindow> window;

    context() {
        states = std::make_unique<Engine::StateManager>();
        window = std::make_unique<sf::RenderWindow>();
    }
};

class Game {
private:
    std::shared_ptr<context> context;
    const sf::Time TIME_PER_SECOND = sf::seconds(1.0 / 60.0);
public:
    Game();
    ~Game();

    void run();
};



#endif //GAME_H
