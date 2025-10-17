#include "potato.h"


Potato::Potato() {
    entity_Name = "Potato";
    yield = 30;        
    price = 5;         
    growthTime = 4;    
    currentAge = 0;    
}


Potato::~Potato() {}


int Potato::sellCrop() {
    if (isReadyToHarvest()) {
        return yield * price;  
        // Plot will handle removal of this object
    }
    return 0; 
}



