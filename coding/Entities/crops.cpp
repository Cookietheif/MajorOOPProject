#include "crops.h"
#include "gameState.h"

Crops::Crops(int buy, int sell, int growTime, int good, int bad, int ID)
    : buyPrice(buy), sellPrice(sell), growthTime(growTime),
      currentAge(0), goodSeason(good), badSeason(bad),
      ungrown_ID(ID), grown_ID(ID+1) {}

void Crops::onBuy(GameState& state) {
    state.modifyMoney(-buyPrice);
    currentAge = 0;
}

void Crops::grow(const GameState& state) {
    seasonalMod(state);
    currentAge++;
}

bool Crops::isReadyToHarvest() const {
    return currentAge >= growthTime;
}

int Crops::sellCrop() {
    if (isReadyToHarvest()) {
        currentAge = 0;
        return sellPrice;
    }
    return 0;
}

void Crops::seasonalMod(const GameState& state) {
    if (state.getSeason() == goodSeason) growthTime = 1;
    else if (state.getSeason() == badSeason) growthTime = 3;
    else growthTime = 2;
}

int Crops::getCurrentID() const {
    if (isReadyToHarvest) {
        return grown_ID;
    } else {
       return ungrown_ID;
    }
}
