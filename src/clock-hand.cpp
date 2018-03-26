#include "clock-hand.hpp"

ClockHand::ClockHand() {
    this->configure(DEFAULT_CLOCK_HAND_POSITION, DEFAULT_CLOCK_HAND_SIZE, DEFAULT_CLOCK_HAND_COLOR);
}

ClockHand::ClockHand(sf::Vector2f position, sf::Vector2f size, sf::Color color) {
    this->configure(position, size, color);
}

void ClockHand::configure(sf::Vector2f position, sf::Vector2f size, sf::Color color) {     
    this->setFillColor(color);
    this->setOrigin(this->getGlobalBounds().width / 2, this->getGlobalBounds().height - 25);
    this->setPosition(position);
}
