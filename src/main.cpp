#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
    //
    // TEST CODE (ONLY SHOWS THE WINDOW)
    //

    sf::RenderWindow window(sf::VideoMode(512, 512), "Snake Game", sf::Style::Close | sf::Style::Resize);

    while (window.isOpen()) {
        sf::Event evnt;
        while (window.pollEvent(evnt)) {
            switch (evnt.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::Resized:
                    std::cout << evnt.size.width << ' ' << evnt.size.height << '\n';
            }

        }

        // Clear the window with black color
        window.clear(sf::Color::Black);

        // Display the current frame
        window.display();
    }

    return 0;
}

