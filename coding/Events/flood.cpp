#include "flood.h"

flood::flood(){
    likelihood = 0.2;
    duration = 3;
}

void flood::spin(){
    std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<int> dist(0,99);
    for (int i = 0; i < 10; i++){
        int rnum = dist(rng);
        std::cout << rnum << std::endl;

        if (rnum < likelihood){
            // reduce yield
        }
        else {
            // do nothing
        }
    }
    
}