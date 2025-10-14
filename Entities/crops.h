#ifndef CROPS_H
#define CROPS_H

#include <iostream>
#include <string>
#include "Entity.h"


class Crops : public Entity {
protected:
    int yield;         // Amount of produce gained when harvested
    int price;         // Selling price per unit
    int growthTime;    // Number of turns required until harvest
    int currentAge;    // Current number of turns grown

public:
    
    Crops();                              // Default constructor
    virtual ~Crops();                     // Virtual destructor

    
    int getYield() const { return yield; }
    int getPrice() const { return price; }
    int getGrowthTime() const { return growthTime; }
    int getCurrentAge() const { return currentAge; }

    
    virtual void grow();                  // Progresses growth each turn
    virtual bool isReadyToHarvest() const; // True if growthTime reached
    virtual int sellCrop() = 0;           // Pure virtual — must define in derived crops
    virtual void seasonalMod() = 0;       // Pure virtual — for seasonal yield adjustments
};

#endif 
