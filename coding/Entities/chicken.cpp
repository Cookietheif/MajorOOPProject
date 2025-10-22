#include "coding/Entities/chicken.h"
#include "coding/gameEngine/gameObjects/gameState/gameState.h"

Chicken::Chicken() : Animals(150, 75, 20, 11) {
    produceAmount = 0;
}

int Chicken::sellAnimal(GameState& state) {
    int money = sellPrice;
    state.modifyMoney(money);
    return money;
}

int Chicken::sellProduce(GameState& state) {
    int money = produceAmount * produceValue;
    state.modifyMoney(money);
    produceAmount = 0;
    return money;
}


void Chicken::grow(const GameState& state) {
    produceAmount++;
}
