#include "strawberry.h"
#include <iostream>
#include <cmath>


Strawberry::Strawberry() {
    entity_Name = "Strawberry";
    yield = 20;        
    price = 6;         
    growthTime = 4;    
    currentAge = 0;   
}


Strawberry::~Strawberry() {}


int Strawberry::sellCrop() {
    if (isReadyToHarvest()) {
        return yield * price;
    }
    return 0;
}


void Strawberry::seasonalMod(const gameEngine& engine) {
    std::string currentSeason = engine.getSeason();

    if (currentSeason == "Summer") {
        yield = static_cast<int>(std::round(yield * 1.25));
    } else if (currentSeason == "Winter") {
        yield = static_cast<int>(std::round(yield * 0.75));
    }
}

