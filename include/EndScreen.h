#ifndef GAMEOVER_H
#define GAMEOVER_H

#include <SFML/Graphics/Text.hpp>
#include "State.hpp"
#include "Game.h"

class EndScreen : public Engine::State {
private:
    std::shared_ptr<Context> context;
    sf::Text endScreenTitle;
    std::string m_title;

    sf::Text scoreText;
    int m_score;
    sf::Text highScoreText;
    int m_highScore;

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
    EndScreen(std::shared_ptr<Context>& context, std::string title, std::string message, int score);
    ~EndScreen() = default;

    void init() override;
    void processInput() override;
    void update(sf::Time deltaTime) override;
    void draw() override;
};
#endif //GAMEOVER_H
