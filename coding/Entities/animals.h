#ifndef ANIMALS_H
#define ANIMALS_H

#include <string>
#include "coding/Entities/entity.h"

class GameState;

class Animals : public Entity {
protected:
    int buyPrice;
    int sellPrice;
    int produceValue;
    int currentAge;
    int produceAmount;

    int ungrown_ID;
    int grown_ID;

public:
    Animals(int buy, int sell, int value, int ID);
    virtual ~Animals();

    int getBuyPrice() const { return buyPrice; }
    int getSellPrice() const { return sellPrice; }
    int getProduceValue() const { return produceValue; }
    int getAge() const { return currentAge; }
    int getProduceAmount() const {return produceAmount;}

    int getCurrentID() const;

    virtual int sellAnimal(GameState& state) = 0;
    virtual int sellProduce(GameState& state) = 0;
    virtual void seasonalMod(const GameState& state) = 0;
    virtual void grow(const GameState& state) { currentAge++; }
    virtual void onBuy(GameState& state);
};

#endif
