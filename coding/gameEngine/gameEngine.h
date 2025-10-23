#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <SFML/Graphics.hpp>
#include "assets.h"
#include "gameState.h"

class gameEngine
{
private:
    //class members
    sf::RenderWindow* window;
    sf::Event gameEvent;

    //Mouse positions
    sf::Vector2i mousePositionWindow;

    //private functions
    void initialiseVariables();
    void initialiseWindow(assets& assets, GameState& gameState);

public:

    //con/destructors
    gameEngine(assets& assets, GameState& gameState);
    virtual ~gameEngine();

    //function
    void updateMousePositions();
    void update(assets& assets, GameState& gameState);
    void pollEvents();
    void render();

    //accessors
    const bool running() const;
    bool prevMousePressed = false;
};

#endif