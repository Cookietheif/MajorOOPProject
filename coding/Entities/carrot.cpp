#include "carrot.h"
#include <iostream>
#include <cmath>


Carrot::Carrot() {
    entity_Name = "Carrot";
    yield = 25;        
    price = 4;         
    growthTime = 3;    
    currentAge = 0;   
} 


Carrot::~Carrot() {}



int Carrot::sellCrop() {
    if (isReadyToHarvest()) {
        return yield * price;
    }
    return 0;
}


void Carrot::seasonalMod(const gameEngine& engine) {
    std::string currentSeason = engine.getSeason();

    if (currentSeason == "Winter") {
        yield = static_cast<int>(std::round(yield * 1.25));
    } else if (currentSeason == "Summer") {
        yield = static_cast<int>(std::round(yield * 0.75));
    }
}
