#include "pig.h"
#include <iostream>

Pig::Pig() {
    entity_Name = "Pig";
    produceRate = 0;        // No produce
    priceProduce = 0;
    priceAnimal = 100;      
    growthRate = 10;        // Value increases $10 per turn
    age = 0;
}

Pig::~Pig() {}

void Pig::grow() {
    age++;
    priceAnimal += growthRate;
    std::cout << entity_Name << " aged one turn. Age: " << age
              << ", value now $" << priceAnimal << std::endl;
}

int Pig::sellAnimal() {
    std::cout << "Sold " << entity_Name << " (age " << age << ") for $" << priceAnimal << std::endl;
    return priceAnimal;
}



void Pig::seasonalMod(const gameEngine& engine) {
    std::string season = engine.getSeason();

    if (season == "Spring") {
        growthRate = 15;   
    } else if (season == "Winter") {
        growthRate = 5;    
    } else {
        growthRate = 10;   
    }

    std::cout << entity_Name << " growth rate adjusted to $" << growthRate
              << " per turn for " << season << "." << std::endl;
}
