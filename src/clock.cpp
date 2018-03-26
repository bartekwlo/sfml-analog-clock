#include "clock.hpp"
#include <iostream>

Clock::Clock(sf::Vector2f center) {
    mCenter = center;
    mHoursHand.configure(center, sf::Vector2f(100, 180), sf::Color::Black);
    mMinutesHand.configure(center, sf::Vector2f(3, 240), sf::Color::Black);
    mSecondsHand.configure(center, sf::Vector2f(2, 260), sf::Color::Red);
    configureClockCircle(center);
    std::cout << mCenter.x << " " << mCenter.y << std::endl;
}

void Clock::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(mClockCircle);
    target.draw(mHoursHand);
    target.draw(mMinutesHand);
    target.draw(mSecondsHand);
}

void Clock::configureClockCircle(sf::Vector2f center) {
    mClockCircle.setRadius(300);
    mClockCircle.setPointCount(100);
    mClockCircle.setFillColor(sf::Color::Red);
    mClockCircle.setOrigin(mClockCircle.getGlobalBounds().width / 2, mClockCircle.getGlobalBounds().height / 2);
    mClockCircle.setPosition(center);
}
