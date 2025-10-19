#include "pig.h"
#include <iostream>

Pig::Pig() {
    entity_Name = "Pig";
    priceAnimal = 50;      // Base sell value
    priceProduce = 0;      // Pigs have no per-turn produce
    valueIncrement = 10;   // Increase in sell value per turn
}

Pig::~Pig() {}

int Pig::sellAnimal() {
    return priceAnimal;
}

int Pig::sellProduce() {
    return 0; // No produce
}

void Pig::seasonalMod(const gameEngine& engine) {
    // Pigs are not affected by season in this example
}

void Pig::grow() {
    priceAnimal += valueIncrement; // Increase sell value each turn
    std::cout << entity_Name << " grew! New value: $" << priceAnimal << std::endl;
}

