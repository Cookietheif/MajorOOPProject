#include "pests.h"

pests::pests(){
    likelihood = 0.3;
    duration = 1;
}

int pests::hit(int monthlyProfit){
    monthlyProfit = monthlyProfit * 0.2;
    return monthlyProfit;
}