#include "coding/Entities/cow.h"
#include "coding/gameEngine/gameObjects/gameState/gameState.h"

Cow::Cow() : Animals(500, 250, 50, 7) {
    produceAmount = 0;
}

int Cow::sellAnimal(GameState& state) {
    int money = sellPrice;
    state.modifyMoney(money);
    return money;
}

int Cow::sellProduce(GameState& state) {
    int money = produceAmount * produceValue;
    state.modifyMoney(money);
    produceAmount = 0;
    return money;
}
    

void Cow::grow(const GameState& state) {
    produceAmount++;
}
