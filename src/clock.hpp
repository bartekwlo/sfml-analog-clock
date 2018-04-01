#ifndef CLOCK_HPP
#define CLOCK_HPP

#include <ctime>
#include <cmath>
#include <iostream>
#include <SFML/Audio.hpp>
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
        sf::Music mTickSoundMusic;
        sf::Text mTickSoundMuteText;

        void configureClockCircle(sf::CircleShape& circle, float radius, sf::Color fillColor);
        void configureClockCircle(sf::CircleShape& circle, float radius, sf::Color fillColor, sf::Color outlineColor, float outlineThickness);
        void createDots();
        void loadTickSoundMusic(std::string soundPath);
        void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    public:
        Clock(sf::Vector2f center);
        void updateTime();
        void switchTickSoundOnOff();
};


#endif
