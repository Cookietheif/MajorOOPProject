#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "./gameObjects/gameState/gameState.h"
#include "./gameObjects/assets.h"

#include "gameEngine.h"
//#include "coding/Entities/entity.cpp"

//private functions
void gameEngine::initialiseVariables() {
    this->window = nullptr;
};
void gameEngine::initialiseWindow(assets assets, GameState gameState) {
    this->window = new sf::RenderWindow(sf::VideoMode(720, 960), "Farming Simulator", sf::Style::Titlebar | sf::Style::Close); //720=9 (tiles) *16 (pixels) *5 (scale for window size), titled Farming Simulator with close button, 9x12 window
    this->window->setFramerateLimit(60); //frame limit

    //default screen
    assets.setBaseScreen(gameState, *this->window);

};

//public functions
// constructor
gameEngine::gameEngine() {
    GameState gameState;
    assets assets;
    gameEngine::initialiseVariables();
    gameEngine::initialiseWindow(assets, gameState);
};

//game function
void gameEngine::pollEvents() {while (this->window->pollEvent(gameEvent)) //loop for game again - constant checking for input and stuff
        {
            if (gameEvent.type == sf::Event::Closed || (gameEvent.type == sf::Event::KeyPressed && gameEvent.key.code == sf::Keyboard::Escape)) { //for the record, switch cases super recommended here, I just don't like them
                this->window->close(); 
            };
        };};

void gameEngine::updateMousePositions() {
    this->mousePositionWindow = sf::Mouse::getPosition(*this->window);
}

void gameEngine::update(assets assets) {
  this->pollEvents();

  // Mouse position
    this->updateMousePositions();

    //check for shop hover for prettiness
    if ((this->mousePositionWindow.y) <= 80 && (this->mousePositionWindow.y >= 0)) { //in top row
        //what tile hovering bordered call
        if (this->mousePositionWindow.x > 80 && this->mousePositionWindow.x <= 160) { //strawberry
            assets.strawberry_seed_bordered_sprite.setPosition(80,0);
            this->window->draw(assets.strawberry_seed_bordered_sprite);
        } else if (this->mousePositionWindow.x > 160 && this->mousePositionWindow.x <= 240) { //carrot
            assets.carrot_seed_bordered_sprite.setPosition(160,0);
            this->window->draw(assets.carrot_seed_bordered_sprite);
        } else if (this->mousePositionWindow.x > 240 && this->mousePositionWindow.x <= 320) { //potato
            assets.potato_seed_bordered_sprite.setPosition(240,0);
            this->window->draw(assets.potato_seed_bordered_sprite);
        } else if (this->mousePositionWindow.x > 320 && this->mousePositionWindow.x <= 400) { //cow
            assets.cow_bordered_sprite.setPosition(320,0);
            this->window->draw(assets.cow_bordered_sprite);
        } else if (this->mousePositionWindow.x > 400 && this->mousePositionWindow.x <= 480) { //pig
            assets.pig_bordered_sprite.setPosition(400,0);
            this->window->draw(assets.pig_bordered_sprite);
        } else if (this->mousePositionWindow.x > 480 && this->mousePositionWindow.x <= 560) { //chicken
            assets.chicken_bordered_sprite.setPosition(400,0);
            this->window->draw(assets.chicken_bordered_sprite);
        }
    }/*
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
        if (mousePositionWindow.x <=) {

        }
    }*/
}

//render/visualise/display game function
void gameEngine::draw() { //draw all sprites
    
}

void gameEngine::render(assets assets, GameState gameState) {
    this->window->clear(sf::Color(0,255,0,255)); //clear old stuff
    assets.setBaseScreen(gameState, *this->window);
    //updates I guess
    this->window->display(); //display new stuff
}

const bool gameEngine::running() const { return this->window->isOpen(); }; //isOpen() returns bool for if window is open, SFML built in function

//destructor
gameEngine::~gameEngine() { //deconstructor ensures freeing space and closes window just in case
    if (this->running()) {this->window->close();}
    delete this->window;
};