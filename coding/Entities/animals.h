#ifndef ANIMALS_H
#define ANIMALS_H

#include <iostream>
#include <string>
#include "./entity.h"
#include "gameEngine.h"

class Animals : public Entity {
protected:
    int produceRate;     
    int priceAnimal;     
    int priceProduce;    
  

public:
   
    Animals();           
    virtual ~Animals();  
   
    virtual void grow() {}; // Default does nothing


    
    int getProduceRate() const { return produceRate; }
    int getPriceAnimal() const { return priceAnimal; }
    int getPriceProduce() const { return priceProduce; }

    
    virtual int sellAnimal() = 0;   
    virtual int sellProduce() = 0;  
    virtual void seasonalMod(const gameEngine& engine) = 0; 
};

#endif 

