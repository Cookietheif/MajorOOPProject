#include "coding/Entities/animals.h"
#include "coding/gameEngine/gameObjects/gameState/gameState.h"

Animals::Animals(int buy, int sell, int value, int ID)
    : buyPrice(buy), sellPrice(sell), produceValue(value), currentAge(0),
      ungrown_ID(ID), grown_ID(ID+1) {}

Animals::~Animals() = default;

void Animals::onBuy(GameState& state) {
    state.modifyMoney(-buyPrice);
    currentAge = 0;
}

int Animals::getCurrentID() const {
    if (produceAmount>0) {
        return grown_ID;
    }else{
        return ungrown_ID;
    }
}
