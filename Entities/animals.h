#ifndef CROPS_H
#define CROPS_H

#include <iostream>
#include <stdio.h>
#include "Entity.h"

class Animals : public Entity{
    int produce;
    int price;

    Animals();
    virtual ~Animals();

    int getProduce() const {return produce;};
    int getPrice() const {return price;};

    virtual int sellAnimal() = 0;
    virtual int sellProduce() = 0;
    virtual void emptyPlot();
    virtual void seasonalMod() = 0;




};


#endif