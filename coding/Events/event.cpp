#include "event.h"
#include <random>
#include <iostream>
#include <cmath>
#include <chrono>


event::event(){
    likelihood = 20;
    duration = 3;
    eventAge = 0;
}

int event::spin(){
    return 1;
}