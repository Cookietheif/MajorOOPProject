//default libraries
#include <iostream>
//SFML libraries
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
//our files
#include "gameEngine.h"
#include "gameState.h"
#include "assets.h"

int main()
{
    //initialise and utilise game engine
    assets assets;
    std::cout << "fart";
    GameState gameState;
    std::cout << "shot";
    gameEngine game(assets, gameState);
    std::cout << "cooter";

    while (game.running()) //loop for game runs stuff
    {
        //update game property stuff
        game.update(assets, gameState);

        //depiction of update
        game.render();
            };
    return 0;
}
