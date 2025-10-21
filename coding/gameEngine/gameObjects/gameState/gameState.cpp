#include "coding/gameEngine/gameObjects/gameState/gameState.h"
#include <iostream>

GameState::GameState() {
    turnNumber = 1;
    money = 1000;
    currentSeason = 1;

    plot1 = plot2 = plot3 = plot4 = plot5 = plot6 = plot7 = plot8 = plot9 = nullptr;
}

GameState::~GameState() {
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
    Entity* plots[9] = { plot1, plot2, plot3, plot4, plot5, plot6, plot7, plot8, plot9 };
    if (plotNumber < 1 || plotNumber > 9) return false;

    Entity*& plotRef = plots[plotNumber - 1];

    if (plotRef != nullptr) {
        std::cout << "Plot " << plotNumber << " already occupied!\n";
        return false;
    }

    int cost = newEntity->getBuyPrice();

    if (money < cost) {
        std::cout << "Not enough money!\n";
        delete newEntity;
        return false;
    }

    money -= cost;
    plotRef = newEntity;
    newEntity->onBuy(*this);

    switch (plotNumber) {
        case 1: plot1 = plotRef; break;
        case 2: plot2 = plotRef; break;
        case 3: plot3 = plotRef; break;
        case 4: plot4 = plotRef; break;
        case 5: plot5 = plotRef; break;
        case 6: plot6 = plotRef; break;
        case 7: plot7 = plotRef; break;
        case 8: plot8 = plotRef; break;
        case 9: plot9 = plotRef; break;
    }

    std::cout << "Bought " << newEntity->getName() << " for $" << cost
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
