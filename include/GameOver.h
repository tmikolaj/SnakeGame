#ifndef GAMEOVER_H
#define GAMEOVER_H

#include <SFML/Graphics/Text.hpp>
#include "State.hpp"
#include "Game.h"

class GameOver : public Engine::State {
private:
    std::shared_ptr<Context> context;
    sf::Text gameOverTitle;

    sf::Text gameOverMessage;
    std::string m_message;

    sf::Text retryButton;
    sf::Text exitButton;

    sf::Color background;

    bool isRetryButtonSelected;
    bool isRetryButtonPressed;

    bool isExitButtonSelected;
    bool isExitButtonPressed;
public:
    GameOver(std::shared_ptr<Context>& context, std::string message);
    ~GameOver();

    void init() override;
    void processInput() override;
    void update(sf::Time deltaTime) override;
    void draw() override;
};
#endif //GAMEOVER_H
