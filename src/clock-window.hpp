#ifndef CLOCK_WINDOW_HPP
#define CLOCK_WINDOW_HPP

#include <SFML/Graphics.hpp>
#include "clock.hpp"

class ClockWindow {
    private:
        const int mWidth;
        const int mHeight;
        sf::RenderWindow mWindow;
        Clock* mClock;

    public:
        ClockWindow(int width, int height);
        ~ClockWindow();

        int mainLoop(); 
};

#endif
