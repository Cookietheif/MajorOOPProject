//default libraries
#include <iostream>
//SFML libraries
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
//our files
#include "gameEngine/gameEngine.cpp"

int main()
{
    //initialise and utilise game engine
    gameEngine game;
    GameState gameState;
    assets assets;

    while (game.running()) //loop for game runs stuff
    {
        //update game property stuff
        game.update(assets, gameState);

        //depiction of update
        game.render(assets, gameState);
            };
    return 0;
}