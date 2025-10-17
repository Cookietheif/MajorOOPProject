#ifndef PIG_H
#define PIG_H

#include "animals.h"

class Pig : public Animals {
private:
    int age;              
    int growthRate;       

public:
    Pig();                       
    virtual ~Pig();              

    void grow();                 
    int sellAnimal() override;   
    void seasonalMod(const gameEngine& engine) override; 
};

#endif
