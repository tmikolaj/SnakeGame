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
    }
}
void MainMenu::update(sf::Time deltaTime) {

}
void MainMenu::draw() {
    context->window->clear();
    context->window->draw(gameTitle);
    context->window->draw(playButton);
    context->window->draw(exitButton);
    context->window->display();
}