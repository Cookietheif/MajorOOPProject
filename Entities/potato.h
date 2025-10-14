#ifndef POTATO_H
#define POTATO_H

#include "crops.h"

class Potato : public Crops {
public:
    
    Potato();
    virtual ~Potato();

   
    int sellCrop() override;       
    void seasonalMod() override;   // No seasonal effect for year-round crop
};

#endif 
