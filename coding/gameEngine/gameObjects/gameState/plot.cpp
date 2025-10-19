#include "./plot.h"
#include "coding/Entities/crops.h"
#include "coding/Entities/animals.h"

Plot::Plot() {
    for (int i = 0; i < NUM_PLOTS; ++i) {
        plots[i] = nullptr;  // All plots start empty
    }
}

bool Plot::plant(int index, std::unique_ptr<Entity> entity) {
    if (index < 0 || index >= NUM_PLOTS) return false;
    if (plots[index] != nullptr) {
        std::cout << "Plot " << index << " is already occupied.\n";
        return false;
    }
    plots[index] = std::move(entity);
    return true;
}

void Plot::remove(int index) {
    if (index < 0 || index >= NUM_PLOTS) return;
    plots[index].reset(); // Deletes the entity and sets plot to empty
}

Entity* Plot::getEntity(int index) const {
    if (index < 0 || index >= NUM_PLOTS) return nullptr;
    return plots[index].get();
}

void Plot::growAll() {
    for (int i = 0; i < NUM_PLOTS; ++i) {
        if (plots[i] != nullptr) {
            // Check if crop
            if (Crops* crop = dynamic_cast<Crops*>(plots[i].get())) {
                crop->grow();
            }
            // Check if animal
            else if (Animals* animal = dynamic_cast<Animals*>(plots[i].get())) {
                animal->grow();
            }
        }
    }
}

void Plot::applySeasonalMod(const gameEngine& engine) {
    for (int i = 0; i < NUM_PLOTS; ++i) {
        if (plots[i] != nullptr) {
            // Crop seasonal adjustment
            if (Crops* crop = dynamic_cast<Crops*>(plots[i].get())) {
                crop->seasonalMod(engine);
            }
            // Animal seasonal adjustment
            else if (Animals* animal = dynamic_cast<Animals*>(plots[i].get())) {
                animal->seasonalMod(engine);
            }
        }
    }
}

void Plot::printStatus() const {
    for (int i = 0; i < NUM_PLOTS; ++i) {
        std::cout << "Plot " << i << ": ";
        if (plots[i] == nullptr) {
            std::cout << "Empty\n";
        } else {
            std::cout << plots[i]->getName() << "\n";
        }
    }
}
