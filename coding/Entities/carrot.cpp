#include "carrot.h"
#include "gameState.h"

Carrot::Carrot() 
    : Crops(5, 10, 2, 4, 2, 3)
{
    entity_Name = "Carrot";
    
}

int Carrot::sellCrop() {
    if (isReadyToHarvest()) {
        currentAge = 0;
        return sellPrice;
    }
    return 0;
}

void Carrot::seasonalMod(const GameState& state) {
    if (state.getSeason() == 4) growthTime = 1; // winter
    else if (state.getSeason() == 2) growthTime = 3; // summer
    else growthTime = 2; // normal
}
