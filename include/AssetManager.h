#pragma once

#include <map>
#include <memory>
#include <string>
#include <SFML/Graphics/Font.hpp>

namespace Engine
{
    class AssetManager
    {
    public:
        AssetManager();
        ~AssetManager();

        void addFont(int id, const std::string& filePath);
        const sf::Font& getFont(int id) const;

    private:
        std::map<int, std::unique_ptr<sf::Font>> fonts;
    };
}