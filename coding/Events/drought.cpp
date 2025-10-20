#include "event.h"
#include "drought.h"

drought::drought(){
    likelihood = 20;
    duration = 3;
}

void drought::spin(){
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