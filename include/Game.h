#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <memory>
#include "StateManager.h"
#include "AssetManager.h"

enum AssetID {
    MAIN_FONT = 0
};

struct Context {
    std::unique_ptr<Engine::StateManager> states;
    std::unique_ptr<sf::RenderWindow> window;
    std::unique_ptr<Engine::AssetManager> assets;

    Context() {
        states = std::make_unique<Engine::StateManager>();
        window = std::make_unique<sf::RenderWindow>();
        assets = std::make_unique<Engine::AssetManager>();
    }
};

class Game {
private:
    std::shared_ptr<Context> context;
    const sf::Time TIME_PER_FRAME = sf::seconds(1.0 / 60.0);
public:
    Game();
    ~Game();

    void run();
};



#endif //GAME_H
