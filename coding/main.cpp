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
    gameEngine game;
    sf::RenderWindow window(sf::VideoMode(720, 960), "Farming Simulator", sf::Style::Titlebar | sf::Style::Close); //Window creation, 9x12, 16 pixel, 5 scale so tile = 80x80 with each "pixel" being 5 pixels
    sf::Event pollingEvent; //event created for use of polling
    window.setFramerateLimit(60); //limit 60 fps

    while (window.isOpen()) //loop for game runs stuff
    {
        //poll events
        while (window.pollEvent(pollingEvent)) //loop for game again - constant checking for input and stuff
        {
            if (pollingEvent.type == sf::Event::Closed || (pollingEvent.type == sf::Event::KeyPressed && pollingEvent.key.code == sf::Keyboard::Escape)) { //for the record, switch cases super recommended here, I just don't like them
                window.close();
                return 1; 
            };
        };

        //update game property stuff

        //depiction of update
        window.clear(sf::Color::Green); //clear old stuff
            //draw new stuff

            window.display(); //for use after done drawing new stuff so that drawed window is displayed
    };
   window.close();
    return 0;
}