#include <iostream>
#include "../include/AssetManager.h"

Engine::AssetManager::AssetManager() {

}
Engine::AssetManager::~AssetManager() {

}
void Engine::AssetManager::addFont(int id, const std::string &filePath) {
    auto font = std::make_unique<sf::Font>();

    if (font->loadFromFile(filePath)) {
        std::cout << "Font loaded successfully\n";
        fonts[id] = std::move(font);
    } else {
        std::cerr << "Failed to load font: " << filePath << '\n';
    }

}
const sf::Font& Engine::AssetManager::getFont(int id) const {
        auto it = fonts.find(id);
        if (it != fonts.end()) {
            return *(it->second);
        } else {
            std::cerr << "Font ID not found: " << id << "\n";
            exit(1);
    }

}