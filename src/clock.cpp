#include "clock.hpp"

Clock::Clock(sf::Vector2f center) {
    mCenter = center;
    mHoursHand.configure(sf::Vector2f(center.x, center.y), sf::Vector2f(8, 150), sf::Color::Black, 100);
    mMinutesHand.configure(sf::Vector2f(center.x, center.y), sf::Vector2f(5, 180), sf::Color::Black, 85);
    mSecondsHand.configure(sf::Vector2f(center.x, center.y), sf::Vector2f(5, 220), sf::Color::Red, 45);
    configureClockCircle(mCenterCircle, 15, sf::Color::Red);
    configureClockCircle(mOutlineCircle, 260, sf::Color::Transparent, sf::Color::Black, 5);
    createDots();

    // play tick sound music
    loadTickSoundMusic("../sound/clock.wav");
    mTickSoundMusic.play();
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

void Clock::loadTickSoundMusic(std::string soundPath) {
    if (!mTickSoundMusic.openFromFile(soundPath)) {
        std::cout << "Could not load sound (music) : " << soundPath << std::endl;
        return;
    }
   
    // make tick sounds loop
    mTickSoundMusic.setLoop(true);

    // make tick sound a little quieter
    mTickSoundMusic.setVolume(50.0);
}

void Clock::switchTickSoundOnOff() {
    if (mTickSoundMusic.getVolume() > 0) {
        mTickSoundMusic.setVolume(0.0);
    } else if (mTickSoundMusic.getVolume() == 0) {
        mTickSoundMusic.setVolume(50.0);
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
