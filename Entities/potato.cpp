#include "potato.h"


Potato::Potato() {
    entity_Name = "Potato";
    yield = 30;        // Units per harvest
    price = 5;         // Price per unit
    growthTime = 4;    // Turns required to mature
    currentAge = 0;    // Starts at zero
}


Potato::~Potato() {}


int Potato::sellCrop() {
    if (isReadyToHarvest()) {
        return yield * price;  
        // Plot will handle removal of this object
    }
    return 0; 
}


void Potato::seasonalMod() {
    // No effect
}
