#include "clock.hpp"

Clock::Clock(sf::Vector2f center) {
    mCenter = center;
    mHoursHand.configure(sf::Vector2f(center.x, center.y-35), sf::Vector2f(10, 150), sf::Color::Black);
    mMinutesHand.configure(sf::Vector2f(center.x, center.y-50), sf::Vector2f(5, 180), sf::Color::Black);
    mSecondsHand.configure(sf::Vector2f(center.x, center.y-90), sf::Vector2f(5, 220), sf::Color::Red);
    configureClockCircle(mCenterCircle, 15, sf::Color::Red);
    configureClockCircle(mOutlineCircle, 260, sf::Color::Transparent, sf::Color::Black, 5);
    createDots();
}

void Clock::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    // draw clock hands
    target.draw(mHoursHand);
    target.draw(mMinutesHand);
    target.draw(mSecondsHand);

    // draw circles
    target.draw(mCenterCircle);
    target.draw(mOutlineCircle);

    // draw dots around outline circle
    for (int i=0; i<60; i++) {
        target.draw(mDots[i]);
    }
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
    int x, y;

    for (int i=0; i<60; i++) {
        x = (centerCircleRadius - 10) * cos(angle);
        y = (centerCircleRadius - 10) * sin(angle);

        if (i%5 == 0)
            mDots[i] = sf::CircleShape(8);
        else
            mDots[i] = sf::CircleShape(4);

        mDots[i].setFillColor(sf::Color::Black);
        mDots[i].setOrigin(mDots[i].getGlobalBounds().width / 2, mDots[i].getGlobalBounds().height / 2);
        mDots[i].setPosition(x + mCenter.x, y + mCenter.y);

        angle = angle + ((2* M_PI)/60);
    }
}

void Clock::updateTime() {
    // get current time
    std::time_t timeNow = std::time(NULL);
    struct tm * ptm = localtime(&timeNow);
    
    // move the hands accordingly
    mSecondsHand.setRotation(ptm->tm_sec*6);
    mMinutesHand.setRotation(ptm->tm_min*6 + (ptm->tm_sec/12));
    mHoursHand.setRotation(ptm->tm_hour*30 + (ptm->tm_min/2));
}
