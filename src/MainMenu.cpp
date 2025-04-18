//
// Created by mikolaj on 4/17/25.
//

#include <iostream>
#include <SFML/Window/Event.hpp>
#include "../include/MainMenu.h"

MainMenu::MainMenu(std::shared_ptr<Context>& context) : context(context) {

}
MainMenu::~MainMenu() {

}
void MainMenu::init() {
    std::cout << "Pointer check: context = " << context.get() << ", assets = " << context->assets.get() << "\n";

    context->assets->addFont(MAIN_FONT, "assets/Roboto-Italic-VariableFont_wdth,wght.ttf");
    gameTitle.setFont(context->assets->getFont(MAIN_FONT));
    gameTitle.setString("Snake Game");
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
    context->window->display();
}