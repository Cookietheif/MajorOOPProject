#ifndef COW_H
#define COW_H

#include "coding/Entities/animals.h"

class Cow : public Animals {
public:
    Cow();
    ~Cow() override = default;

    int sellAnimal(GameState& state) override;
    int sellProduce(GameState& state) override;
    void seasonalMod(const GameState& state) override;
    void grow(const GameState& state) override;
};

#endif
