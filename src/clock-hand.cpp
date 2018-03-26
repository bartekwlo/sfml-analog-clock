#include "clock-hand.hpp"

ClockHand::ClockHand(sf::Vector2f position, sf::Vector2f size, sf::Color color) {
    this->configure(position, size, color);
}

void ClockHand::configure(sf::Vector2f position, sf::Vector2f size, sf::Color color) {     
    this->setFillColor(color);
    this->setOrigin(this->getGlobalBounds().width / 2, this->getGlobalBounds().height - 25);
    this->setSize(size);
    this->setPosition(position);
}
