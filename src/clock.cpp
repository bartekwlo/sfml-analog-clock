#include "clock.hpp"

Clock::Clock(sf::Vector2f center) {
    mCenter = center;
    mHoursHand.configure(sf::Vector2f(center.x, center.y-35), sf::Vector2f(10, 150), sf::Color::Black);
    mMinutesHand.configure(sf::Vector2f(center.x, center.y-50), sf::Vector2f(5, 180), sf::Color::Black);
    mSecondsHand.configure(sf::Vector2f(center.x, center.y-90), sf::Vector2f(5, 220), sf::Color::Red);
    configureClockCircle(mCenterCircle, 15, sf::Color::Red);
    configureClockCircle(mOutlineCircle, 260, sf::Color::White, sf::Color::Black, 2);
}

void Clock::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(mOutlineCircle);
    target.draw(mHoursHand);
    target.draw(mMinutesHand);
    target.draw(mSecondsHand);
    target.draw(mCenterCircle);
}

void Clock::configureClockCircle(sf::CircleShape& circle, float radius, sf::Color fillColor) {
    circle.setRadius(radius);
    circle.setPointCount(400);
    circle.setFillColor(fillColor);
    circle.setOrigin(circle.getGlobalBounds().width / 2,circle.getGlobalBounds().height / 2);
    circle.setPosition(mCenter);
}

void Clock::configureClockCircle(sf::CircleShape& circle, float radius, sf::Color fillColor, sf::Color outlineColor, float outlineThickness) {
    configureClockCircle(circle, radius, fillColor);
    circle.setOutlineColor(outlineColor);
    circle.setOutlineThickness(outlineThickness);
}

void Clock::createDots() {
// github.com/SFML/SFML/wiki/Source:-Analog-Clock/
    float angle = 0.0;
    float centerCircleRadius = mOutlineCircle.getRadius();

    for (int i=0; i<60; i++) {
        x = centerCircleRadius * cos(angle);
        y = centerCircleRadius * sin(angle);


    }
}
