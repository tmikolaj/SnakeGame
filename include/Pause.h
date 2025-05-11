#ifndef PAUSE_H
#define PAUSE_H

#include <SFML/Graphics/Text.hpp>
#include "State.hpp"
#include "Game.h"

class Pause : public Engine::State {
private:
    std::shared_ptr<Context> context;
    sf::Text title;
public:
    Pause(std::shared_ptr<Context>& context);
    ~Pause() = default;

    void init() override;
    void processInput() override;
    void update(sf::Time deltaTime) override;
    void draw() override;
};

#endif //PAUSE_H
