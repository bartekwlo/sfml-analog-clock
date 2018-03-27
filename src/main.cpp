#include <iostream>
#include <ctime>
#include <cmath>
#include "clock.hpp"
#include "clock-window.hpp"

int main(int argc, char *argv[]) {

    ClockWindow cwin(800, 600);
    
    int ret;
    ret = cwin.mainLoop();

    return ret;
}
