#ifndef CARROT_H
#define CARROT_H

#include "crops.h"

class Carrot : public Crops {
public:
    Carrot();
    ~Carrot() override = default;

    int sellCrop() override;
    void seasonalMod(const GameState& state);

    int getUngrownID() const { return ungrown_ID; }
    int getGrownID() const { return grown_ID; }
};

#endif
