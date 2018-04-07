#include <iostream>
#include "clock.hpp"
#include "clock-window.hpp"

int main(int argc, char *argv[]) {

    ClockWindow cwin(CLOCK_WINDOW_SIZE_DEFAULT);
    
    int ret;
    ret = cwin.mainLoop();

    return ret;
}
