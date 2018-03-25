#include "clock-window.hpp"

ClockWindow::ClockWindow(int width, int height) : mWidth(width), mHeight(height) {
    mClock = new Clock();
    mWindow.create(sf::VideoMode(mWidth, mHeight), "SFML Analog Clock");
}

ClockWindow::~ClockWindow() {
    delete mClock;
}

int ClockWindow::mainLoop() {
    while (mWindow.isOpen()) {
        sf::Event event;
        while (mWindow.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                mWindow.close();
        }
    }  

    mWindow.clear();
    mWindow.display();
    
    return 0;
}

Clock* ClockWindow::getClock() {
    return mClock;
}