#include "clock-window.hpp"

// ClockWindow class constructor
ClockWindow::ClockWindow(int width, int height) : mWidth(width), mHeight(height), mClock(sf::Vector2f(width/2.0f, height/2.0f)) {
    mWindow.create(sf::VideoMode(mWidth, mHeight), "SFML Analog Clock");
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
                    mClock.switchTickSoundOnOff();
            }
        }

        mWindow.clear(sf::Color::White);
        mClock.updateTime();
        mWindow.draw(mClock);
        mWindow.display();
    }  
    
    return 0;
}

