#include "clock.hpp"

Clock::Clock(sf::Vector2f center) {
    mCenter = center;
    mHoursHand.configure(center, sf::Vector2f(100, 180), sf::Color::Black);
    mMinutesHand.configure(center, sf::Vector2f(3, 240), sf::Color::Black);
    mSecondsHand.configure(center, sf::Vector2f(2, 260), sf::Color::Red);
    configureClockCircle(center);
}

void Clock::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(mHoursHand);
    target.draw(mMinutesHand);
    target.draw(mSecondsHand);
}
