#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include "gameEngine.h"

//private functions
void gameEngine::initialiseVariables() {
    this->window = nullptr;
};
void gameEngine::initialiseWindow() {
    this->window = new sf::RenderWindow(sf::VideoMode(720, 960), "Farming Simulator", sf::Style::Titlebar | sf::Style::Close);
    this->window.setFramerateLimit(60);
};

//public functions
// constructor
gameEngine::gameEngine() {
    gameEngine::initialiseVariables();
    gameEngine::initialiseWindow();
};

//destructor
gameEngine::~gameEngine() {
    delete this->window;
};

//game function
void gameEngine::update() {};

//render/visualise/display game function
void gameEngine::render() {};