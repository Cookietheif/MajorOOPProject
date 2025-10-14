#ifndef ANIMALS_H
#define ANIMALS_H

#include <iostream>
#include <string>
#include "Entity.h"

class Animals : public Entity {
protected:
    int produceRate;     // Goods produced per turn (e.g. milk, eggs)
    int priceAnimal;     // Price of the animal when sold
    int priceProduce;    // Price of one unit of produce
  

public:
   
    Animals();           // Default constructor
    virtual ~Animals();  // Virtual destructor

    
    int getProduceRate() const { return produceRate; }
    int getPriceAnimal() const { return priceAnimal; }
    int getPriceProduce() const { return priceProduce; }

    
    virtual int sellAnimal() = 0;   // Each derived animal defines how it's sold
    virtual int sellProduce() = 0;  // Defines how produce is sold
    virtual void seasonalMod() = 0; // Adjusts stats per season
};

#endif 

