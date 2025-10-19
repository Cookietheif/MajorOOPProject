#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <iostream>
#include <string>
#include <memory>
#include "coding/Entities/crops.h"
#include "coding/Entities/animals.h"
#include "gameEngine.h"

class GameState {
private:
    int turnNumber;
    std::string currentSeason;
    int money;

    // 9 possible plot slots
    Entity* plot1;
    Entity* plot2;
    Entity* plot3;
    Entity* plot4;
    Entity* plot5;
    Entity* plot6;
    Entity* plot7;
    Entity* plot8;
    Entity* plot9;

    // Helper function
    void updateSeason();

public:
    GameState();
    ~GameState();

    // Accessors
    int getTurnNumber() const { return turnNumber; }
    std::string getSeason() const { return currentSeason; }
    int getMoney() const { return money; }

    Entity* getPlot(int index) const;

    // Turn control
    void nextTurn();

    // Plot and money management
    bool buyEntity(int plotNumber, Entity* newEntity);
    bool sellEntity(int plotNumber);

    // Growth and progression
    void growAll();
};

#endif
