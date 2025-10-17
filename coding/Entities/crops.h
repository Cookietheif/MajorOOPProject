#ifndef CROPS_H
#define CROPS_H

#include <iostream>
#include <string>
#include "./Entity.h"
#include "gameEngine.h"



class Crops : public Entity {
protected:
    int yield;         
    int price;         
    int growthTime;    
    int currentAge;    

public:
    
    Crops();                              
    virtual ~Crops();                     

    
    int getYield() const { return yield; }
    int getPrice() const { return price; }
    int getGrowthTime() const { return growthTime; }
    int getCurrentAge() const { return currentAge; }

    
    virtual void grow();                  
    virtual bool isReadyToHarvest() const; 
    virtual int sellCrop() = 0;          
    virtual void seasonalMod(const gameEngine& engine) = 0;     
};

#endif 
