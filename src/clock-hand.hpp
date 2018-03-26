#ifndef CLOCK_HAND_HPP
#define CLOCK_HAND_HPP

#include <SFML/Graphics.hpp>

class ClockHand : public sf::RectangleShape {
    private:
    public:
        ClockHand(sf::Vector2f position, sf::Vector2f size, sf::Color color);
        void configure(sf::Vector2f position, sf::Vector2f size, sf::Color color);
};

#endif

