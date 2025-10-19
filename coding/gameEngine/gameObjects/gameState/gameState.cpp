#include "coding/gameEngine/gameObjects/gameState/gameState.h"
#include "coding/Entities/potato.h"
#include "coding/Entities/carrot.h"
#include "coding/Entities/strawberry.h"
#include "coding/Entities/cow.h"
#include "coding/Entities/chicken.h"
#include "coding/Entities/pig.h"

GameState::GameState() {
    turnNumber = 1;
    money = 1000;
    currentSeason = "Spring";

    // Initialize all plots as empty
    plot1 = plot2 = plot3 = plot4 = plot5 = plot6 = plot7 = plot8 = plot9 = nullptr;
}

GameState::~GameState() {
    // Clean up any remaining entities
    Entity* plots[9] = { plot1, plot2, plot3, plot4, plot5, plot6, plot7, plot8, plot9 };
    for (auto& p : plots) {
        delete p;
        p = nullptr;
    }
}

Entity* GameState::getPlot(int index) const {
    switch (index) {
        case 1: return plot1;
        case 2: return plot2;
        case 3: return plot3;
        case 4: return plot4;
        case 5: return plot5;
        case 6: return plot6;
        case 7: return plot7;
        case 8: return plot8;
        case 9: return plot9;
        default: return nullptr;
    }
}

bool GameState::buyEntity(int plotNumber, Entity* newEntity) {
    // Check for valid plot
    Entity*& plotRef = *([&]() -> Entity** {
        switch (plotNumber) {
            case 1: return &plot1;
            case 2: return &plot2;
            case 3: return &plot3;
            case 4: return &plot4;
            case 5: return &plot5;
            case 6: return &plot6;
            case 7: return &plot7;
            case 8: return &plot8;
            case 9: return &plot9;
            default: return &plot1;
        }
    })();

    if (plotRef != nullptr) {
        std::cout << "Plot " << plotNumber << " already occupied!\n";
        return false;
    }

    // Determine cost (using price from crop or animal)
    Crops* c = dynamic_cast<Crops*>(newEntity);
    Animals* a = dynamic_cast<Animals*>(newEntity);

    int cost = 0;
    if (c) cost = c->getPrice();
    else if (a) cost = a->getPriceAnimal();

    if (money < cost) {
        std::cout << "Not enough money!\n";
        delete newEntity;
        return false;
    }

    money -= cost;
    plotRef = newEntity;

    std::cout << "Bought " << newEntity->getName() << " for $" << cost 
              << " and placed it in plot " << plotNumber << ".\n";
    return true;
}

bool GameState::sellEntity(int plotNumber) {
    Entity*& plotRef = *([&]() -> Entity** {
        switch (plotNumber) {
            case 1: return &plot1;
            case 2: return &plot2;
            case 3: return &plot3;
            case 4: return &plot4;
            case 5: return &plot5;
            case 6: return &plot6;
            case 7: return &plot7;
            case 8: return &plot8;
            case 9: return &plot9;
            default: return &plot1;
        }
    })();

    if (!plotRef) {
        std::cout << "No entity in plot " << plotNumber << " to sell.\n";
        return false;
    }

    int income = 0;
    if (auto c = dynamic_cast<Crops*>(plotRef)) {
        if (c->isReadyToHarvest()) {
            income = c->sellCrop();
            std::cout << "Harvested " << c->getName() << " for $" << income << "!\n";
        } else {
            std::cout << c->getName() << " is not ready to harvest.\n";
            return false;
        }
    } else if (auto a = dynamic_cast<Animals*>(plotRef)) {
        income = a->sellAnimal();
        std::cout << "Sold " << a->getName() << " for $" << income << "!\n";
    }

    money += income;
    delete plotRef;
    plotRef = nullptr;

    return true;
}

void GameState::nextTurn() {
    turnNumber++;
    updateSeason();
    growAll();
}

void GameState::updateSeason() {
    int month = (turnNumber - 1) % 12;

    if (month < 3) currentSeason = "Spring";
    else if (month < 6) currentSeason = "Summer";
    else if (month < 9) currentSeason = "Autumn";
    else currentSeason = "Winter";
}

void GameState::growAll() {
    Entity* plots[9] = { plot1, plot2, plot3, plot4, plot5, plot6, plot7, plot8, plot9 };
    for (auto& p : plots) {
        if (!p) continue;

        if (auto c = dynamic_cast<Crops*>(p))
            c->grow();
        else if (auto a = dynamic_cast<Animals*>(p))
            a->grow();
    }
}
