#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "coding/Entities/entity.h"
#include "coding/Entities/crops.h"
#include "coding/Entities/animals.h"

class GameState {
private:
    int turnNumber;
    int currentSeason;
    int money;
    int seedSelected;

    Entity* plot1;
    Entity* plot2;
    Entity* plot3;
    Entity* plot4;
    Entity* plot5;
    Entity* plot6;
    Entity* plot7;
    Entity* plot8;
    Entity* plot9;

    void updateSeason();

public:
    GameState();
    ~GameState();

    int getTurnNumber() const { return turnNumber; }
    int getSeason() const { return currentSeason; } // 1=spring, 2=summer, 3=autumn, 4=winter
    int getMoney() const { return money; }
    int getSeedSelected() const {return seedSelected;}
    void setSeedSelected(int a) {seedSelected = a;}

    void modifyMoney(int amount) { money += amount; }
    Entity* getPlot(int index) const;

    void nextTurn();
    bool buyEntity(int plotNumber, int entityType);
    bool sellEntity(int plotNumber);
    void growAll();

    // Event management
    void spinEvent();
};

#endif
