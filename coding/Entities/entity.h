#ifndef ENTITY_H
#define ENTITY_H

#include <string>

class GameState;

class Entity {
protected:
    int entity_ID;           
    std::string entity_Name;
    int buyPrice;
    int sellPrice;

public:
    Entity();
    virtual ~Entity();

    std::string getName() const { return entity_Name; }
    int getID() const { return entity_ID; }
    int sell(GameState& state) { return sellPrice; }
    
    virtual int getBuyPrice() const { return buyPrice; }
    virtual int getSellPrice() const { return sellPrice; }
    virtual void grow(GameState& state) {}
    virtual void onBuy(GameState& state) {}
    virtual int getCurrentID() const = 0;
};

#endif
