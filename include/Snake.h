#ifndef SNAKE_H
#define SNAKE_H

#include <list>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>

class Snake : public sf::Drawable {
private:
    std::list<sf::RectangleShape> body;
    std::list<sf::RectangleShape>::iterator head;
    std::list<sf::RectangleShape>::iterator tail;
public:
    Snake();
    ~Snake() = default;

    void init();
    void move(const sf::Vector2f& direction);
    bool isOn(const sf::RectangleShape& other) const;
    void grow(const sf::Vector2f& direction);
    sf::Vector2f getHeadPos() const;
    bool isSelfColliding() const;
    std::list<sf::RectangleShape>& getBody();

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};



#endif //SNAKE_H
