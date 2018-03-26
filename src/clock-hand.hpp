#ifndef CLOCK_HAND_HPP
#define CLOCK_HAND_HPP

#include <SFML/Graphics.hpp>

class ClockHand : sf::RectangleShape {
    private:
    public:
        ClockHand();
        ClockHand(sf::Vector2f size, sf::Color color);
        void configure();
};

#endif

