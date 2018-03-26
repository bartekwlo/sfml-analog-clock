#include "clock.hpp"
#include <iostream>

Clock::Clock(sf::Vector2f center) {
    mCenter = center;
    mHoursHand.configure(center, sf::Vector2f(5, 180), sf::Color::Black);
    mMinutesHand.configure(center, sf::Vector2f(3, 240), sf::Color::Black);
    mSecondsHand.configure(center, sf::Vector2f(2, 260), sf::Color::Red);
    configureClockCenterCircle();
    std::cout << mCenter.x << " " << mCenter.y << std::endl;
}

void Clock::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(mClockCenterCircle);
    target.draw(mHoursHand);
    target.draw(mMinutesHand);
    target.draw(mSecondsHand);
}

void Clock::configureClockCenterCircle() {
    mClockCenterCircle.setRadius(200);
    mClockCenterCircle.setPointCount(100);
    mClockCenterCircle.setFillColor(sf::Color::Red);
    mClockCenterCircle.setOrigin(mClockCenterCircle.getGlobalBounds().width / 2, mClockCenterCircle.getGlobalBounds().height / 2);
    mClockCenterCircle.setPosition(mCenter);
}
