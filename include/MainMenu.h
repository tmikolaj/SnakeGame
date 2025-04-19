//
// Created by mikolaj on 4/17/25.
//

#ifndef MAINMENU_H
#define MAINMENU_H

#include <SFML/Graphics/Text.hpp>
#include "State.hpp"
#include "Game.h"

class MainMenu : public Engine::State {
private:
    std::shared_ptr<Context> context;
    sf::Text gameTitle;

    sf::Text playButton;
    sf::Text exitButton;

    sf::Color background;

    bool isPlayButtonSelected;
    bool isPlayButtonPressed;

    bool isExitButtonSelected;
    bool isExitButtonPressed;
public:
    MainMenu(std::shared_ptr<Context>& context);
    ~MainMenu();

    void init() override;
    void processInput() override;
    void update(sf::Time deltaTime) override;
    void draw() override;
};



#endif //MAINMENU_H
