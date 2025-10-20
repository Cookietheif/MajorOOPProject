#ifndef CROPS_H
#define CROPS_H

#include <iostream>
#include <string>

#include "entity.h"


class gameEngine; 

class Crops : public Entity {
protected:
    int yield;         
    int buyPrice;      
    int sellPrice;     
    int growthTime;    
    int currentAge;    

public:
    Crops();
    virtual ~Crops();

    
    int getYield() const { return yield; }
    int getBuyPrice() const { return buyPrice; }
    int getSellPrice() const { return sellPrice; }
    int getGrowthTime() const { return growthTime; }
    int getCurrentAge() const { return currentAge; }

    
    virtual void grow();
    virtual bool isReadyToHarvest() const;
    virtual int sellCrop() = 0;
    virtual void seasonalMod(const gameEngine& engine) = 0;
    virtual void onBuy() { currentAge = 0; } 
};

#endif
