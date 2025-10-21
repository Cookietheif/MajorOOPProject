#ifndef PIG_H
#define PIG_H

#include "coding/Entities/animals.h"

class Pig : public Animals {
private:
    double currentValue;
public:
    Pig();
    ~Pig() override = default;

    int sellAnimal(GameState& state) override;
    int sellProduce(GameState& state) override;
    void seasonalMod(const GameState& state) override;
    void grow(const GameState& state) override;
};

#endif
