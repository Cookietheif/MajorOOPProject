#ifndef CROPS_H
#define CROPS_H

#include <iostream>
#include <stdio.h>
#include "Entity.h"

class Crops : public Entity{
    int yield;
    int price;
    int growthTime;

    Crops();
    virtual ~Crops();

    int getYield() const {return yield;};
    int getPrice() const {return price;};

    virtual int sellCrop() = 0;
    virtual void emptyPlot();
    virtual void seasonalMod() = 0;




};


#endif