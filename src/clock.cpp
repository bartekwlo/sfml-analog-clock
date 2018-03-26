#include "clock.hpp"

Clock::Clock() {

}

Clock::Clock(sf::Vector2f center) {
    mHoursHand.configure(center, sf::Vector2f(5, 180), sf::Color::Black);
    mMinutesHand.configure(center, sf::Vector2f(3, 240), sf::Color::Black);
    mSecondsHand.configure(center, sf::Vector2f(2, 260), sf::Color::Red);
}

void Clock::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(mHoursHand);
    target.draw(mMinutesHand);
    target.draw(mSecondsHand);
}
