#ifndef CLOCK_WINDOW_HPP
#define CLOCK_WINDOW_HPP

#include <SFML/Graphics.hpp>
#include "clock.hpp"

#define CLOCK_WINDOW_SIZE_1 sf::Vector2u(800, 600)
#define CLOCK_WINDOW_SIZE_2 sf::Vector2u(450, 340)
#define CLOCK_WINDOW_SIZE_3 sf::Vector2u(300, 225)
#define CLOCK_WINDOW_SIZE_DEFAULT CLOCK_WINDOW_SIZE_1

class ClockWindow {
    private:
        const int mWidth;
        const int mHeight;
        sf::RenderWindow mWindow;
        Clock mClock;

    public:
        ClockWindow(sf::Vector2u size);

        int mainLoop(); 
};
#endif
