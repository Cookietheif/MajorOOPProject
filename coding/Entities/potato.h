#ifndef POTATO_H
#define POTATO_H

#include "crops.h"

class Potato : public Crops {
public:
    Potato();
    ~Potato() override {}

    int sellCrop() override;
    void seasonalMod(const GameState& state);

    int getBuyPrice() const override { return buyPrice; }
    int getSellPrice() const override { return sellPrice; }
};

#endif
