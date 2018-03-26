#ifndef CLOCK_HPP
#define CLOCK_HPP

#include <SFML/Graphics.hpp>
#include "clock-hand.hpp"

#define DEFAULT_CLOCK_CENTRE sf::Vector2f(400, 300);

class Clock : public sf::Drawable {
    private:
        ClockHand mHoursHand;
        ClockHand mMinutesHand;
        ClockHand mSecondsHand;

    public:
        Clock();
        Clock(sf::Vector2f center);
        void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};


#endif
