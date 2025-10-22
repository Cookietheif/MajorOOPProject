#ifndef CHICKEN_H
#define CHICKEN_H

#include "animals.h"

class Chicken : public Animals {
public:
    Chicken();
    ~Chicken() override = default;

    int sellAnimal(GameState& state) override;
    int sellProduce(GameState& state) override;
    void seasonalMod(const GameState& state) override {};
    void grow(const GameState& state) override;
};

#endif
