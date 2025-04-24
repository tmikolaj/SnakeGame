#include <ctime>
#include "../include/Game.h"

int main() {
    srand(static_cast<unsigned>(time(nullptr)));
    Game game;
    game.run();
    return 0;
}

