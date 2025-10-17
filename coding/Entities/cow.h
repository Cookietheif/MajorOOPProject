#ifndef COW_H
#define COW_H

#include "animals.h"

class Cow : public Animals {
public:
    
    Cow();
    virtual ~Cow();

   
    int sellAnimal() override;       
    int sellProduce() override;      
    void seasonalMod(const gameEngine& engine) override;     
};

#endif 
