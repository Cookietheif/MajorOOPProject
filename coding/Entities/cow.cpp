#include "cow.h"
#include <algorithm>
#include <iostream>


Cow::Cow() {
    entity_Name = "Cow";
    produceRate = 5;      
    priceAnimal = 500;    
    priceProduce = 20;    
}


Cow::~Cow() {}


int Cow::sellAnimal() {
    return priceAnimal;
}


int Cow::sellProduce() {
    int total = produceRate * priceProduce;
    return total;
}


void Cow::seasonalMod(const gameEngine& engine) {
    std::string season = engine.getSeason();

    if (season == "Spring") {
        produceRate = 8;   
    } else if (season == "Winter") {
        produceRate = 3;   
    } else {
        produceRate = 5;   
    }

    std::cout << entity_Name << " production rate adjusted to " << produceRate
              << " milk per turn for " << season << "." << std::endl;
}
