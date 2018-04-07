#include "clock-window.hpp"

// ClockWindow class constructor
ClockWindow::ClockWindow(sf::Vector2u size) : mWidth(size.x), mHeight(size.y), mClock(sf::Vector2f(size.x/2.0f, size.y/2.0f)) {
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
                switch (event.key.code) {
                    case sf::Keyboard::M:
                        mClock.switchTickSoundOnOff();
                        break;
                    case sf::Keyboard::Num1:
                        mWindow.setSize(CLOCK_WINDOW_SIZE_1);
                        break;
                    case sf::Keyboard::Num2:
                        mWindow.setSize(CLOCK_WINDOW_SIZE_2);
                        break;
                    case sf::Keyboard::Num3:
                        mWindow.setSize(CLOCK_WINDOW_SIZE_3);
                        break;
                    default:
                        break;
                }
            }
        }

        mWindow.clear(sf::Color::White);
        mClock.updateTime();
        mWindow.draw(mClock);
        mWindow.display();
    }  
    
    return 0;
}

