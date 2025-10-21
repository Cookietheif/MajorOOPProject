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
    int currentSeason;
    int money;
    int seedSelected;

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
    int getSeason() const { return currentSeason; } // 1 = spring, 2 summer, 3 autumn, 4 winter
    int getMoney() const { return money; }
    int getSeedSelected() const {return seedSelected;}
    void setSeedSelected(int a) {seedSelected = a;}

    Entity* getPlot(int index) const;

    // Turn control
    void nextTurn();

    // Plot and money management
    bool buyEntity(int plotNumber, Entity* newEntity);
    bool sellEntity(int plotNumber);

    // Growth and progression
    void growAll();

    // Event management
    void spinEvent();
};

#endif
