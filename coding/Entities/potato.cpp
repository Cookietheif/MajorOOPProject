#include "coding/Entities/potato.h"
#include "coding/gameEngine/gameObjects/gameState/gameState.h"

Potato::Potato() 
    : Crops(5, 10, 3, 5, 5, 5)
{
    entity_Name = "Strawberry";
    
}

int Potato::sellCrop() {
    if (isReadyToHarvest()) {
        currentAge = 0;
        return sellPrice;
    }
    return 0;
}

void Potato::seasonalMod(const GameState& state) {
    growthTime = 3;
}
