#ifndef CLOCK_HPP
#define CLOCK_HPP

#include <SFML/Graphics.hpp>
#include "clock-hand.hpp"

class Clock : public sf::Drawable {
    private:
        ClockHand hoursHand;
        ClockHand minutesHand;
        ClockHand secondsHand;

    public:
        Clock();
        void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};


#endif
