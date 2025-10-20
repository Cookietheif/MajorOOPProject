#include "event.h"
#include <random>
#include <time.h>
#include <iostream>

event::event(){
    likelihood = 0.2;
    duration = 3;
    eventAge = 0;
}

void event::spin(){
    srand(time(0));
    for (int i = 0; i < 10; i++){
        double rnum = double(rand()) /RAND_MAX;
        std::cout << rnum << std::endl;
    }
    
}