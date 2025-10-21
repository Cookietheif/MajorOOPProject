#include "event.h"
#include "drought.h"

drought::drought(){
    likelihood = 20;
    duration = 3;
}

int drought::spin(){
    std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<int> dist(0,99);
    int rnum = dist(rng);
    std::cout << rnum << std::endl;

    if (rnum < likelihood){
        return 0.8;
    }
    else {
        return 1;
    }   
    
}