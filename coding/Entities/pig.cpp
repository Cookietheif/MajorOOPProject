#include "coding/Entities/pig.h"
#include "coding/gameEngine/gameObjects/gameState/gameState.h"
#include <cmath>

Pig::Pig() : Animals(400, 0, 0, 9) {
    // Pig starts at 75% of its buy value
    sellPrice = static_cast<int>(std::round(buyPrice * 0.75));
    produceAmount = 0;
}

int Pig::sellAnimal(GameState& state) {
    int money = sellPrice;
    state.modifyMoney(money);
    return money;
}


void Pig::grow(const GameState& state) {
    // Increase value by 20% each turn
    sellPrice = static_cast<int>(std::round(sellPrice * 1.2));
}
