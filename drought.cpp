#include "drought.h"

drought::drought(){
    likelihood = 0.2;
    duration = 2;
}

int drought::hit(int monthlyProfit){
    monthlyProfit = monthlyProfit * 0.2;
    return monthlyProfit;
}