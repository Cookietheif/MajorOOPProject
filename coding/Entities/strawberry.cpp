#include "coding/Entities/strawberry.h"
#include "gameState.h"

Strawberry::Strawberry() 
    : Crops(5, 10, 2, 2, 4, 1)
{
    entity_Name = "Strawberry";
    
}

int Strawberry::sellCrop() {
    if (isReadyToHarvest()) {
        currentAge = 0;
        return sellPrice;
    }
    return 0;
}

void Strawberry::seasonalMod(const GameState& state) {
    if (state.getSeason() == 2) growthTime = 1; // summer
    else if (state.getSeason() == 4) growthTime = 3; // winter
    else growthTime = 2; // normal
}
