#ifndef PLOT_H
#define PLOT_H

#include "coding/Entities/entity.h"
#include <array>
#include <memory>
#include <iostream>

const int NUM_PLOTS = 9;

class Plot {
private:
    std::array<std::unique_ptr<Entity>, NUM_PLOTS> plots;

public:
    Plot();  // Constructor initializes all plots as empty

    // Place an entity (crop or animal) in a plot
    bool plant(int index, std::unique_ptr<Entity> entity);

    // Remove an entity from a plot
    void remove(int index);

    // Access an entity at a plot
    Entity* getEntity(int index) const;

    // Advance growth for all entities in the plots
    void growAll();

    // Apply seasonal effects to all entities
    void applySeasonalMod(const class gameEngine& engine);

    // Debug: print status of all plots
    void printStatus() const;
};

#endif
