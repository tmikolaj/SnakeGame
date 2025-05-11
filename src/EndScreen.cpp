#include <SFML/Window/Event.hpp>
#include <fstream>
#include <string>
#include <iostream>
#include "../include/EndScreen.h"
#include "../include/GamePlay.h"

EndScreen::EndScreen(std::shared_ptr<Context>& context, std::string title, std::string message, int score) : context(context), isRetryButtonSelected(true), isRetryButtonPressed(false), isExitButtonSelected(false), isExitButtonPressed(false), m_title(title), m_message(message), m_score(score) {
    std::ifstream file("highscore.txt");
    std::string line;
    if (!file) {
        std::cerr << "File for high score doesn't exist, creating it...\n";
        std::ofstream createFile("highscore.txt");
        createFile << 0; // Initial score
        createFile.close();
        m_highScore = 0;
    } else {
        std::string line;
        if (getline(file, line)) {
            m_highScore = std::stoi(line);
        } else {
            m_highScore = 0;
        }
    }

}
void EndScreen::init() {
    // Background color init
    background.r = 32;
    background.g = 99;
    background.b = 8;

    // Title init
    endScreenTitle.setFont(context->assets->getFont(MAIN_FONT));
    endScreenTitle.setString(m_title);
    endScreenTitle.setColor(sf::Color::White);
    endScreenTitle.setOrigin(endScreenTitle.getLocalBounds().width/2 + 40,endScreenTitle.getLocalBounds().height/2);
    endScreenTitle.setPosition(context->window->getSize().x / 2, context->window->getSize().y / 2 - 150);
    endScreenTitle.setCharacterSize(50);

    // Game over message init
    gameOverMessage.setFont(context->assets->getFont(MAIN_FONT));
    gameOverMessage.setString(m_message);
    gameOverMessage.setCharacterSize(20);
    gameOverMessage.setOrigin(gameOverMessage.getLocalBounds().width / 2, gameOverMessage.getLocalBounds().height / 2 - 20);
    gameOverMessage.setPosition(context->window->getSize().x / 2, context->window->getSize().y / 2 - 100);

    // Scores
    // Score display init
    scoreText.setFont(context->assets->getFont(MAIN_FONT));
    scoreText.setString("Score: "+std::to_string(m_score));
    scoreText.setCharacterSize(20);
    scoreText.setOrigin(scoreText.getLocalBounds().width / 2, scoreText.getLocalBounds().height / 2 - 20);
    scoreText.setPosition(context->window->getSize().x / 2 - 60, context->window->getSize().y / 2 - 70);
    // High score display init
    // Saving score to file
    if (m_score > m_highScore) {
        m_highScore = m_score;
        std::ofstream file("highscore.txt");
        if (file.is_open()) {
            file << m_highScore;
            file.close();
        } else {
            std::cerr << "Unable to open file (for saving)!\n";
        }
    }
    highScoreText.setFont(context->assets->getFont(MAIN_FONT));
    highScoreText.setString("High score: "+std::to_string(m_highScore));
    highScoreText.setCharacterSize(20);
    highScoreText.setOrigin(scoreText.getLocalBounds().width / 2, scoreText.getLocalBounds().height / 2 - 20);
    highScoreText.setPosition(context->window->getSize().x / 2 + 70, context->window->getSize().y / 2 - 70);

    // Buttons
    // Play button
    retryButton.setFont(context->assets->getFont(MAIN_FONT));
    retryButton.setString("RETRY");
    retryButton.setOrigin(retryButton.getLocalBounds().width/2,retryButton.getLocalBounds().height/2);
    retryButton.setPosition(context->window->getSize().x / 2, context->window->getSize().y / 2);
    retryButton.setCharacterSize(20);
    // Exit button
    exitButton.setFont(context->assets->getFont(MAIN_FONT));
    exitButton.setString("EXIT");
    exitButton.setOrigin(exitButton.getLocalBounds().width/2,exitButton.getLocalBounds().height/2);
    exitButton.setPosition(context->window->getSize().x / 2 - 7, context->window->getSize().y / 2 + 50);
    exitButton.setCharacterSize(20);
}
void EndScreen::processInput() {
    sf::Event evnt;
    while (context->window->pollEvent(evnt)) {
        if (evnt.type == sf::Event::Closed) {
            context->window->close();
        }
        else if (evnt.type == sf::Event::KeyPressed) {
            switch (evnt.key.code) {
                case sf::Keyboard::Up:
                    if (!isRetryButtonSelected) {
                        isRetryButtonSelected = true;
                        isExitButtonSelected = false;
                    }
                    break;
                case sf::Keyboard::Down:
                    if (!isExitButtonSelected) {
                        isExitButtonSelected = true;
                        isRetryButtonSelected = false;
                    }
                    break;
                case sf::Keyboard::Return:
                    isRetryButtonPressed = false;
                    isExitButtonPressed = false;

                    if (isRetryButtonSelected) {
                        isRetryButtonPressed = true;
                    } else {
                        isExitButtonPressed = true;
                    }
                    break;
                default:
                    break;
            }
        }
    }
}
void EndScreen::update(sf::Time deltaTime) {
    if (isRetryButtonSelected) {
        // reset exit button hover style
        exitButton.setFillColor(sf::Color::White);
        exitButton.setCharacterSize(20);

        retryButton.setFillColor(sf::Color::Black);
        retryButton.setCharacterSize(23);
    } else {
        // reset play button hover style
        retryButton.setFillColor(sf::Color::White);
        retryButton.setCharacterSize(20);

        exitButton.setFillColor(sf::Color::Black);
        exitButton.setCharacterSize(23);
    }

    if (isRetryButtonPressed) {
        context->states->add(std::make_unique<GamePlay>(context), true);
    } else if (isExitButtonPressed) {
        context->window->close();
    }
}
void EndScreen::draw() {
    context->window->clear(background);
    context->window->draw(endScreenTitle);
    context->window->draw(gameOverMessage);
    context->window->draw(scoreText);
    context->window->draw(highScoreText);
    context->window->draw(retryButton);
    context->window->draw(exitButton);
    context->window->display();
}
