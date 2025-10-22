#include "event.h"
#include "boost.h"

boost::boost(){
    likelihood = 5; // setting the likelihood of the event
}

double boost::spin(){
    std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<int> dist(0,99); // creating a uniformally distributed random variable between 0 and 99
    int rnum = dist(rng); // generating a random number between 0 and 99 

    if (rnum < likelihood){ // 20% chance of event hitting
        std::cout << "MONEY BOOST HAS HIT! YOUR BALANCE HAS BEEN DOUBLED!" << std::endl;
        return 2.0; // if it hits message displayed and money multiplier returned
    }
    else {
        return 1.0; // if not then money multiplied by 1 (stays the same)
    }
    
}