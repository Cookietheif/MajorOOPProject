#include "pests.h"

pests::pests(){
    likelihood = 0.2;
    duration = 3;
}

int pests::spin(){
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