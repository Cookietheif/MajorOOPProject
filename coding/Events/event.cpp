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

void event::spin(){
    // nothing
}