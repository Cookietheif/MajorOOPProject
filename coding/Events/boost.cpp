#include "event.h"
#include "boost.h"

boost::boost(){
    likelihood = 5;
    duration = 3;
}

int boost::spin(){
    std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<int> dist(0,99);
    int rnum = dist(rng);
    std::cout << rnum << std::endl;

    if (rnum < likelihood){
        return 2;
    }
    else {
        return 1;
    }
    
}