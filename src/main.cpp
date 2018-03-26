#include <iostream>
#include <ctime>
#include <cmath>
#include "clock.hpp"
#include "clock-window.hpp"

int main(int argc, char *argv[]) {

    ClockWindow cwin(1024, 768);
    
    int ret;
    ret = cwin.mainLoop();

    return ret;
}
