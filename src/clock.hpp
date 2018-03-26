#ifndef CLOCK_HPP
#define CLOCK_HPP

#include <SFML/Graphics.hpp>
#include "clock-hand.hpp"

class Clock : public sf::Drawable {
    private:
        sf::Vector2f mCenter;
        ClockHand mHoursHand;
        ClockHand mMinutesHand;
        ClockHand mSecondsHand;
        sf::CircleShape mClockCenterCircle;
    
        void configureClockCircle(sf::CircleShape& circle, float radius, sf::Color fillColor);
        void configureClockCircle(sf::CircleShape& circle, float radius, sf::Color fillColor, sf::Color outlineColor, float outlineThickness);
        void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    public:
        Clock(sf::Vector2f center);
};


#endif
