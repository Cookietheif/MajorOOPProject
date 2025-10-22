#ifndef PIG_H
#define PIG_H

#include "animals.h"

class Pig : public Animals {
public:
    Pig();
    ~Pig() override = default;

    int sellAnimal(GameState& state) override;
    int sellProduce(GameState& state) override {};
    void seasonalMod(const GameState& state) override {};
    void grow(const GameState& state) override;
};

#endif
