#include <SFML/Window/Event.hpp>
#include "../include/EndScreen.h"
#include "../include/GamePlay.h""

EndScreen::EndScreen(std::shared_ptr<Context>& context, std::string title, std::string message) : context(context), isRetryButtonSelected(true), isRetryButtonPressed(false), isExitButtonSelected(false), isExitButtonPressed(false), m_title(title), m_message(message) {

}
EndScreen::~EndScreen() {

}
void EndScreen::init() {
    // Background color init
    background.r = 32;
    background.g = 99;
    background.b = 8;

    // Title init
    gameOverTitle.setFont(context->assets->getFont(MAIN_FONT));
    gameOverTitle.setString(m_title);
    gameOverTitle.setOrigin(gameOverTitle.getLocalBounds().width/2,gameOverTitle.getLocalBounds().height/2);
    gameOverTitle.setPosition(context->window->getSize().x / 2, context->window->getSize().y / 2 - 150);

    // Game over message init
    gameOverMessage.setFont(context->assets->getFont(MAIN_FONT));
    gameOverMessage.setString(m_message);
    gameOverMessage.setCharacterSize(20);
    gameOverMessage.setOrigin(gameOverMessage.getLocalBounds().width / 2, gameOverMessage.getLocalBounds().height / 2);
    gameOverMessage.setPosition(context->window->getSize().x / 2, context->window->getSize().y / 2 - 100);

    // Buttons
    // Play button
    retryButton.setFont(context->assets->getFont(MAIN_FONT));
    retryButton.setString("RETRY");
    retryButton.setOrigin(retryButton.getLocalBounds().width/2,retryButton.getLocalBounds().height/2);
    retryButton.setPosition(context->window->getSize().x / 2, context->window->getSize().y / 2 - 25);
    retryButton.setCharacterSize(20);
    // Exit button
    exitButton.setFont(context->assets->getFont(MAIN_FONT));
    exitButton.setString("EXIT");
    exitButton.setOrigin(exitButton.getLocalBounds().width/2,exitButton.getLocalBounds().height/2);
    exitButton.setPosition(context->window->getSize().x / 2, context->window->getSize().y / 2 + 25);
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
    context->window->draw(gameOverTitle);
    context->window->draw(gameOverMessage);
    context->window->draw(retryButton);
    context->window->draw(exitButton);
    context->window->display();
}
