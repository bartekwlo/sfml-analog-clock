#include "clock.hpp"

Clock::Clock(sf::Vector2f center) {
    mCenter = center;
    mHoursHand.configure(center, sf::Vector2f(5, 180), sf::Color::Black);
    mMinutesHand.configure(center, sf::Vector2f(3, 240), sf::Color::Black);
    mSecondsHand.configure(center, sf::Vector2f(2, 260), sf::Color::Red);
    configureClockCircle(mCenterCircle, 50, sf::Color::Red);
    configureClockCircle(mOutlineCircle, 260, sf::Color::White, sf::Color::Red, 2);
}

void Clock::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(mOutlineCircle);
    target.draw(mCenterCircle);
    target.draw(mHoursHand);
    target.draw(mMinutesHand);
    target.draw(mSecondsHand);
}

void Clock::configureClockCircle(sf::CircleShape& circle, float radius, sf::Color fillColor) {
    circle.setRadius(radius);
    circle.setPointCount(200);
    circle.setFillColor(fillColor);
    circle.setOrigin(circle.getGlobalBounds().width / 2,circle.getGlobalBounds().height / 2);
    circle.setPosition(mCenter);
}

void Clock::configureClockCircle(sf::CircleShape& circle, float radius, sf::Color fillColor, sf::Color outlineColor, float outlineThickness) {
    configureClockCircle(circle, radius, fillColor);
    circle.setOutlineColor(outlineColor);
    circle.setOutlineThickness(outlineThickness);
}
