#ifndef CLOCK_HAND_HPP
#define CLOCK_HAND_HPP

#include <SFML/Graphics.hpp>

#define DEFAULT_CLOCK_HAND_SIZE sf::Vector2f(3, 240)
#define DEFAULT_CLOCK_HAND_COLOR sf::Color::Black
#define DEFAULT_CLOCK_HAND_POSITION sf::Vector2f(400, 300)
#define DEFAULT_CLOCK_HAND_ORIGIN_MOVEMENT 25

class ClockHand : public sf::RectangleShape {
    private:
    public:
        ClockHand();
        void configure(sf::Vector2f position, sf::Vector2f size, sf::Color color, int originMovement);
};

#endif

