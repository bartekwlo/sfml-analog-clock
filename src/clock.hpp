#ifndef CLOCK_HPP
#define CLOCK_HPP

#include <SFML/Graphics.hpp>

class Clock : public sf::Drawable {
    private:
        sf::RectangleShape hoursHand;
        sf::RectangleShape minutesHand;
        sf::RectangleShape secondsHand;

    public:
        Clock();
};


#endif
