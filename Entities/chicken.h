#ifndef CHICKEN_H
#define CHICKEN_H

#include "animals.h"


class Chicken : public Animals {
public:
    Chicken();                      
    virtual ~Chicken();             

    void grow();                    
    int sellAnimal() override;      
    int sellProduce() override;     
    void seasonalMod(const gameEngine& engine) override; 
};

#endif
