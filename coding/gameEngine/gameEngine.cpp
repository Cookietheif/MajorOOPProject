#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include "gameEngine.h"
//#include "coding/Entities/entity.cpp"

//private functions
void gameEngine::initialiseVariables() {
    this->window = nullptr;
};
void gameEngine::initialiseWindow() {
    this->window = new sf::RenderWindow(sf::VideoMode(720, 960), "Farming Simulator", sf::Style::Titlebar | sf::Style::Close); //720=9 (tiles) *16 (pixels) *5 (scale for window size), titled Farming Simulator with close button
    this->window->setFramerateLimit(60); //frame limit
};

sf::Sprite gameEngine::createSprites(Entity sprite) { //for loading all textures into sprites into game
    Entity::texture.loadFromFile("coding/gameEngine/gameObjects/assets/test.png"); // returns true bool if file exists and stores texture in testTexture
    // if (!testTexture.loadFromFile("coding/gameEngine/gameObjects/assets/test.png")) {std::cout<<"no file";} test to check if file exists
    this->sprite.setTexture(texture); //sets sprite to testTexture
    //test.setPosition(5,5);
    sprite.setScale(5.f,5.f);
    return (sprite);
}

//public functions
// constructor
gameEngine::gameEngine() {
    gameEngine::initialiseVariables();
    gameEngine::initialiseWindow();
};

//destructor
gameEngine::~gameEngine() { //deconstructor ensures freeing space and closes window just in case
    if (this->running()) {this->window->close();}
    delete this->window;
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

void gameEngine::update() {
  this->pollEvents();

  // Mouse position
    this->updateMousePositions();
   // if (gameEvent.) for lmb functionality
}

//render/visualise/display game function
void gameEngine::draw() { //draw all sprites
    gameEngine::createSprites();
}

void gameEngine::render() {
    this->window->clear(sf::Color(0,255,0,255)); //clear old stuff
    this->window->draw(test);
    this->window->display(); //display new stuff
}

const bool gameEngine::running() const { return this->window->isOpen(); }; //isOpen() returns bool for if window is open, SFML built in function