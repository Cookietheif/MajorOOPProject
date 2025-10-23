#include "gameState.h"

#include <iostream>
#include "potato.h"
#include "carrot.h"
#include "strawberry.h"
#include "cow.h"
#include "chicken.h"
#include "pig.h"
#include "assets.h"
#include "event.h"
#include "drought.h"
#include "flood.h"
#include "pests.h"
#include "disease.h"



GameState::GameState() {
    turnNumber = 1;
    money = 1000;
    currentSeason = 1;
    seedSelected = 0;

    plot1 = plot2 = plot3 = plot4 = plot5 = plot6 = plot7 = plot8 = plot9 = nullptr;
}

GameState::~GameState() {
    Entity* plots[9] = { plot1, plot2, plot3, plot4, plot5, plot6, plot7, plot8, plot9 };
    for (auto& p : plots) {
        delete p;
        p = nullptr;
    }
}

bool GameState::checkMoney(int a) { switch (a) {
    case 1:
        if (getMoney() >= 5){
        return true;} else {return false;}
        break;
    case 2:
        if (getMoney() >= 5){
        return true;} else {return false;}
        break;
    case 3:
        if (getMoney() >= 5){
        return true;} else {return false;}
        break;
    case 4:
        if (getMoney() >= 500){
        return true;} else {return false;}
        break;
    case 5:
        if (getMoney() >= 400){
        return true;} else {return false;};
        break;
    case 6:
        if (getMoney() >= 150){
        return true;} else {return false;};
        break;
    default:
        return false;
        break;
    };
}

Entity* GameState::getPlot(int index) const {
  switch (index) {
    case 1:
      return plot1;
      break;
    case 2:
      return plot2;
      break;
    case 3:
      return plot3;
      break;
    case 4:
      return plot4;
      break;
    case 5:
      return plot5;
      break;
    case 6:
      return plot6;
      break;
    case 7:
      return plot7;
      break;
    case 8:
      return plot8;
      break;
    case 9:
      return plot9;
      break;
    default:
      return nullptr;
      break;
  }
}

bool GameState::buyEntity(int plotNumber, int entityType) {
    if (plotNumber < 1 || plotNumber > 9) {
        std::cout << "Invalid plot number!\n";
        return false;
    }

    
    Entity** plotPtr = nullptr;
    switch (plotNumber) {
        case 1: plotPtr = &plot1; break;
        case 2: plotPtr = &plot2; break;
        case 3: plotPtr = &plot3; break;
        case 4: plotPtr = &plot4; break;
        case 5: plotPtr = &plot5; break;
        case 6: plotPtr = &plot6; break;
        case 7: plotPtr = &plot7; break;
        case 8: plotPtr = &plot8; break;
        case 9: plotPtr = &plot9; break;
        default: return false;
    }

    if (*plotPtr != nullptr) {
        std::cout << "Plot " << plotNumber << " already occupied!\n";
        return false;
    }

    
    Entity* newEntity = nullptr;
    switch (entityType) {
        case 1: newEntity = new Strawberry(); break;
        case 2: newEntity = new Carrot();     break;
        case 3: newEntity = new Potato();     break;
        case 4: newEntity = new Cow();        break;
        case 5: newEntity = new Pig();        break;
        case 6: newEntity = new Chicken();    break;
        default:
            std::cout << "Invalid entity type!\n";
            return false;
    }

    
    int cost = newEntity->getBuyPrice();
    Crops* c = dynamic_cast<Crops*>(newEntity);
    Animals* a = dynamic_cast<Animals*>(newEntity);
    
    if (c) cost = c->getBuyPrice();
    else if (a) cost = a->getBuyPrice();

    if (money < cost) {
        std::cout << "Not enough money to buy " << newEntity->getName() << "!\n";
        delete newEntity;
        return false;
    }

    *plotPtr = newEntity;
    newEntity->onBuy(*this);

    std::cout << "Bought " << newEntity->getName()
              << " for $" << cost
              << " and placed it in plot " << plotNumber << ".\n";

    return true;
}


bool GameState::sellEntity(int plotNumber) {
    Entity* plots[9] = { plot1, plot2, plot3, plot4, plot5, plot6, plot7, plot8, plot9 };
    if (plotNumber < 1 || plotNumber > 9) return false;

    Entity*& plotRef = plots[plotNumber - 1];

    if (!plotRef) {
        std::cout << "No entity in plot " << plotNumber << " to sell.\n";
        return false;
    }

    int income = plotRef->sell(*this);
    money += income;

    delete plotRef;
    plotRef = nullptr;

    switch (plotNumber) {
        case 1: plot1 = nullptr; break;
        case 2: plot2 = nullptr; break;
        case 3: plot3 = nullptr; break;
        case 4: plot4 = nullptr; break;
        case 5: plot5 = nullptr; break;
        case 6: plot6 = nullptr; break;
        case 7: plot7 = nullptr; break;
        case 8: plot8 = nullptr; break;
        case 9: plot9 = nullptr; break;
    }

    return true;
}


void GameState::nextTurn() {
    turnNumber++;
    updateSeason();
    growAll();
    spinEvent();
}

void GameState::updateSeason() {
    int month = (turnNumber - 1) % 12;
    if (month < 3) currentSeason = 1;        // spring
    else if (month < 6) currentSeason = 2;   // summer
    else if (month < 9) currentSeason = 3;   // autumn
    else currentSeason = 4;                  // winter
}

void GameState::growAll() {
    Entity* plots[9] = { plot1, plot2, plot3, plot4, plot5, plot6, plot7, plot8, plot9 };
    for (auto& p : plots) {
        if (!p) continue;

        if (auto c = dynamic_cast<Crops*>(p))
            c->grow(*this);
        else if (auto a = dynamic_cast<Animals*>(p))
            a->grow(*this);
    }
}

void GameState::spinEvent(){
    int month = (turnNumber - 1) % 12;

    event* posEvent = new event;
    double posMultiplier = posEvent->spin();
    money *= posMultiplier;

    if (month == 1 || month == 4 || month == 7 || month == 11){
        event* negEvent = new event();
        switch (currentSeason) {
            case 1: {
                pests* springEvent = new pests();
                negEvent = springEvent;
                break;}
            case 2: {
                drought* summerEvent = new drought();
                negEvent = summerEvent;
                break; }
            case 3: {
                disease* autumnEvent = new disease();
                negEvent = autumnEvent;
                break; }
            case 4: {
                flood* winterEvent = new flood();
                negEvent = winterEvent;
                break; }                                            
            default: {
                break;}
        } 
        double negMultiplier = negEvent->spin();
        money *= negMultiplier;
    }
}
