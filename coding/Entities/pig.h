#ifndef PIG_H
#define PIG_H

#include "animals.h"
#include <string>

class Pig : public Animals {
private:
    int valueIncrement;  // How much the sell price increases per turn

public:
    Pig();
    virtual ~Pig();

    // Override virtual functions
    virtual int sellAnimal() override;
    virtual int sellProduce() override;
    virtual void seasonalMod(const gameEngine& engine) override;

    // New: grow increases the pig's sell value
    virtual void grow() override;
};

#endif
