#ifndef CARROT_H
#define CARROT_H

#include "crops.h"

class Carrot : public Crops {
public:
    
    Carrot();
    virtual ~Carrot();

    
    int sellCrop() override;       
    void seasonalMod(const gameEngine& engine) override;
   
};

#endif 
 