#include "chicken.h"
#include <iostream>

Chicken::Chicken() {
    entity_Name = "Chicken";
    produceRate = 2;       
    priceProduce = 5;      
    priceAnimal = 50;      
}

Chicken::~Chicken() {}

void Chicken::grow() {
    int income = produceRate * priceProduce;
    std::cout << entity_Name << " produced eggs worth $" << income << " this turn." << std::endl;
}

int Chicken::sellAnimal() {
    std::cout << "Sold " << entity_Name << " for $" << priceAnimal << std::endl;
    return priceAnimal;
}

int Chicken::sellProduce() {
    int income = produceRate * priceProduce;
    return income;
}

void Chicken::seasonalMod(const gameEngine& engine) {
    std::string season = engine.getSeason();

    if (season == "Spring") {
        produceRate = 3;   
    } else if (season == "Winter") {
        produceRate = 1;   
    } else {
        produceRate = 2;   
    }

    std::cout << entity_Name << " production rate adjusted to " << produceRate
              << " eggs per turn for " << season << "." << std::endl;
}
