#ifndef ANIMALS_H
#define ANIMALS_H

#include <iostream>
#include <string>
#include "entity.h"
#include "gameEngine.h"

class Animals : public Entity {
protected:
    int produceRate;     // Goods produced per turn (e.g. milk, eggs)
    int priceAnimal;     // Price of the animal when sold
    int priceProduce;    // Price of one unit of produce
  

public:
   
    Animals();           
    virtual ~Animals();  

    
    int getProduceRate() const { return produceRate; }
    int getPriceAnimal() const { return priceAnimal; }
    int getPriceProduce() const { return priceProduce; }

    
    virtual int sellAnimal() = 0;   
    virtual int sellProduce() = 0;  
    virtual void seasonalMod(const gameEngine& engine) = 0; 
};

#endif 

