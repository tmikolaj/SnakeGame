//
// Created by mikolaj on 4/17/25.
//

#include <SFML/Window/Event.hpp>
#include "../include/MainMenu.h"

MainMenu::MainMenu(std::shared_ptr<Context>& context) : context(context), isPlayButtonSelected(true), isPlayButtonPressed(false), isExitButtonSelected(false), isExitButtonPressed(false) {

}
MainMenu::~MainMenu() {

}
void MainMenu::init() {
    context->assets->addFont(MAIN_FONT, "assets/Roboto-Italic-VariableFont_wdth,wght.ttf");

    // Background color init
    background.r = 11;
    background.g = 133;
    background.b = 17;

    // Title init
    gameTitle.setFont(context->assets->getFont(MAIN_FONT));
    gameTitle.setString("Snake Game");
    gameTitle.setOrigin(gameTitle.getLocalBounds().width/2,gameTitle.getLocalBounds().height/2);
    gameTitle.setPosition(context->window->getSize().x / 2, context->window->getSize().y / 2 - 150);

    // Buttons
    // Play button
    playButton.setFont(context->assets->getFont(MAIN_FONT));
    playButton.setString("PLAY");
    playButton.setOrigin(playButton.getLocalBounds().width/2,playButton.getLocalBounds().height/2);
    playButton.setPosition(context->window->getSize().x / 2, context->window->getSize().y / 2 - 25);
    playButton.setCharacterSize(20);
    // Exit button
    exitButton.setFont(context->assets->getFont(MAIN_FONT));
    exitButton.setString("EXIT");
    exitButton.setOrigin(exitButton.getLocalBounds().width/2,exitButton.getLocalBounds().height/2);
    exitButton.setPosition(context->window->getSize().x / 2, context->window->getSize().y / 2 + 25);
    exitButton.setCharacterSize(20);
}
void MainMenu::processInput() {
    sf::Event evnt;
    while (context->window->pollEvent(evnt)) {
        if (evnt.type == sf::Event::Closed) {
            context->window->close();
        }
        else if (evnt.type == sf::Event::KeyPressed) {
            switch (evnt.key.code) {
                case sf::Keyboard::Up:
                    if (!isPlayButtonSelected) {
                        isPlayButtonSelected = true;
                        isExitButtonSelected = false;
                    }
                    break;
                case sf::Keyboard::Down:
                    if (!isExitButtonSelected) {
                        isExitButtonSelected = true;
                        isPlayButtonSelected = false;
                    }
                    break;
                case sf::Keyboard::Return:
                    isPlayButtonPressed = false;
                    isExitButtonPressed = false;

                    if (isPlayButtonSelected) {
                        isPlayButtonSelected = true;
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
void MainMenu::update(sf::Time deltaTime) {
    if (isPlayButtonSelected) {
        // reset exit button hover style
        exitButton.setFillColor(sf::Color::White);
        exitButton.setCharacterSize(20);

        playButton.setFillColor(sf::Color::Black);
        playButton.setCharacterSize(23);
    } else {
        // reset play button hover style
        playButton.setFillColor(sf::Color::White);
        playButton.setCharacterSize(20);

        exitButton.setFillColor(sf::Color::Black);
        exitButton.setCharacterSize(23);
    }

    if (isPlayButtonPressed) {
        // Start game
        // Will be implemented soon
    } else if (isExitButtonPressed) {
        context->window->close();
    }
}
void MainMenu::draw() {
    context->window->clear(background);
    context->window->draw(gameTitle);
    context->window->draw(playButton);
    context->window->draw(exitButton);
    context->window->display();
}