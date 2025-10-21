#ifndef STRAWBERRY_H
#define STRAWBERRY_H

#include "coding/Entities/crops.h"

class Strawberry : public Crops {
public:
    Strawberry();
    virtual ~Strawberry();

    int sellCrop() override;                       
    void seasonalMod(const GameState& state);
};

#endif
