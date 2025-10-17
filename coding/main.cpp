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

    while (game.running()) //loop for game runs stuff
    {
        //update game property stuff
        game.update();

        //draw new stuff
        game.draw();

        //depiction of update
        game.render();
            };
    return 0;
}