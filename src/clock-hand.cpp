#include "clock-hand.hpp"

ClockHand::ClockHand() {
    this->configure(DEFAULT_CLOCK_HAND_POSITION, DEFAULT_CLOCK_HAND_SIZE, DEFAULT_CLOCK_HAND_COLOR, DEFAULT_CLOCK_HAND_ORIGIN_MOVEMENT);
}

void ClockHand::configure(sf::Vector2f position, sf::Vector2f size, sf::Color color, int originMovement) {     
    this->setFillColor(color);
    this->setOrigin(this->getGlobalBounds().width / 2, this->getGlobalBounds().height - originMovement);
    this->setSize(size);
    this->setPosition(position);
}
