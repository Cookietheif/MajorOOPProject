#ifndef CROPS_H
#define CROPS_H

#include <string>
#include "coding/Entities/entity.h"

class GameState;

class Crops : public Entity {
protected:
    int buyPrice;
    int sellPrice;
    int growthTime;
    int currentAge;
    int goodSeason;
    int badSeason;

    int ungrown_ID;
    int grown_ID;

public:
    Crops(int buy, int sell, int growTime, int good, int bad, int ID);
    virtual ~Crops() = default;

    int getBuyPrice() const { return buyPrice; }
    int getSellPrice() const { return sellPrice; }

    void grow(const GameState& state);
    bool isReadyToHarvest() const;
    virtual int sellCrop();
    void onBuy(GameState& state);
    void seasonalMod(const GameState& state);

    int getCurrentID() const;
};

#endif
