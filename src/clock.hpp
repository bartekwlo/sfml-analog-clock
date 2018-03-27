#ifndef CLOCK_HPP
#define CLOCK_HPP

#include <ctime>
#include <cmath>
#include <SFML/Graphics.hpp>
#include "clock-hand.hpp"

class Clock : public sf::Drawable {
    private:
        sf::Vector2f mCenter;
        ClockHand mHoursHand;
        ClockHand mMinutesHand;
        ClockHand mSecondsHand;
        sf::CircleShape mCenterCircle;
        sf::CircleShape mOutlineCircle;
        sf::CircleShape mDots[60];

        void configureClockCircle(sf::CircleShape& circle, float radius, sf::Color fillColor);
        void configureClockCircle(sf::CircleShape& circle, float radius, sf::Color fillColor, sf::Color outlineColor, float outlineThickness);
        void createDots();
        void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    public:
        Clock(sf::Vector2f center);
        void setTime(); // unused
        void updateTime();
};


#endif
