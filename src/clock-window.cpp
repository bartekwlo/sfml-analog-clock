#include "clock-window.hpp"

// ClockWindow class constructor
ClockWindow::ClockWindow(int width, int height) : mWidth(width), mHeight(height) {
    mWindow.create(sf::VideoMode(mWidth, mHeight), "SFML Analog Clock");
    mClock = new Clock(sf::Vector2f(mWindow.getSize().x / 2.0f, mWindow.getSize().y / 2.0f));
}

// ClockWindow class destructor
ClockWindow::~ClockWindow() {
    delete mClock;
}

// ClockWindow main event loop method
int ClockWindow::mainLoop() {
    while (mWindow.isOpen()) {
        sf::Event event;
        while (mWindow.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                mWindow.close();

            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::M)
                    mClock->switchTickSoundOnOff();
            }
        }

        mWindow.clear(sf::Color::White);
        mClock->updateTime();
        mWindow.draw(*mClock);
        mWindow.display();
    }  
    
    return 0;
}

