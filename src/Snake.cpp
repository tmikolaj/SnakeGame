#include "../include/Snake.h"

Snake::Snake() : body(std::list<sf::RectangleShape>(4)) {
    head = --body.end();
    tail = body.begin();
}
void Snake::init() {
    // TILE_SIZE is set to 20
    float x = 5 * 20;
    float y = 7 * 20;

    for (auto& piece : body) {
        piece.setFillColor(sf::Color(31, 103, 237));
        piece.setSize(sf::Vector2f(20, 20));
        piece.setPosition(x, y);
        x += 20;
    }
}
void Snake::move(const sf::Vector2f& direction) {
    tail->setPosition(head->getPosition() + direction);
    head = tail;
    ++tail;

    if (tail == body.end()) {
        tail = body.begin();
    }
}
bool Snake::isOn(const sf::RectangleShape& other) const {
    return head->getGlobalBounds().intersects(other.getGlobalBounds());
}
void Snake::grow(const sf::Vector2f& direction) {
    sf::RectangleShape newPiece;

    newPiece.setFillColor(sf::Color(31, 103, 237));
    newPiece.setSize(sf::Vector2f(20, 20));
    newPiece.setPosition(head->getPosition() + direction);

    head = body.insert(++head, newPiece);
}
void Snake::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    for (auto& piece : body) {
        target.draw(piece);
    }
}
sf::Vector2f Snake::getHeadPos() const {
    return head->getPosition();
}
bool Snake::isSelfColliding() const {
    bool flag = false;

    for (auto piece = body.begin(); piece != body.end(); ++piece) {
        if (head != piece) {
            flag = isOn(*piece);
            if (flag) {
                break;
            }
        }
    }

    return flag;
}
std::list<sf::RectangleShape>& Snake::getBody() {
    return body;
}