#include "event.h"
#include <random>
#include <iostream>
#include <cmath>
#include <chrono>


event::event(){
    likelihood = 20;
}

double event::spin(){
    return 1.0;
}