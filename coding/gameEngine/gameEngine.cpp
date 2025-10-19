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
    this->window = new sf::RenderWindow(sf::VideoMode(720, 960), "Farming Simulator", sf::Style::Titlebar | sf::Style::Close); //720=9 (tiles) *16 (pixels) *5 (scale for window size), titled Farming Simulator with close button, 9x12 window
    this->window->setFramerateLimit(60); //frame limit

    //default screen
    gameEngine::setBaseScreen();

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

    //check for shop hover for prettiness
    if ((this->mousePositionWindow.y) <= 80 && (this->mousePositionWindow.y >= 0)) { //in top row
        //what tile hovering bordered call
        if (this->mousePositionWindow.x > 80 && this->mousePositionWindow.x <= 160) { //strawberry

        } else if (this->mousePositionWindow.x > 160 && this->mousePositionWindow.x <= 240) { //carrot

        } else if (this->mousePositionWindow.x > 240 && this->mousePositionWindow.x <= 320) { //potato
        
        } else if (this->mousePositionWindow.x > 320 && this->mousePositionWindow.x <= 400) { //cow
            
        } else if (this->mousePositionWindow.x > 400 && this->mousePositionWindow.x <= 480) { //pig

        } else if (this->mousePositionWindow.x > 480 && this->mousePositionWindow.x <= 560) { //chicken
        
        }

    }
}

//render/visualise/display game function
void gameEngine::draw() { //draw all sprites
    gameEngine::createSprites();
}

void gameEngine::setBaseScreen() {
    //weather
    .setPosition(0,0); //(0,0)
    this->window->draw();
    //seeds
        //Strawberry
        strawberry.setPosition(80,0); //(1,0)
        this->window->draw(strawberry);
        //Carrot
        carrot.setPosition(160,0); //(2,0)
        this->window->draw(carrot);
        //potato
        potato.setPosition(240,0); //(3,0)
        this->window->draw(potato);
    //animals
        //cow
        cow.setPosition(320,0); //(4,0)
        this->window->draw(cow);
        //pig
        pig.setPosition(400,0); //(5,0)
        this->window->draw(pig);
        //chicken
        chicken.setPosition(480,0); //(6,0)
        this->window->draw(chicken);
    //coin symbol //probably move this bit to other function
    sf::Texture coinTexture;
    sf::Sprite coinSprite;
    coinTexture.loadFromFile("./gameObjects/assets/coin.png");
    coinSprite.setTexture(coinTexture);
    coinSprite.setPosition(560,0); //(7,0)
    this->window->draw(coinSprite);
    //fences
        //move elsewhere also
        sf::Texture* fenceTexture[7];
        sf::Sprite* fenceSprite[7];
        for (int i = 0; i < 7; i++) { //from 1st to 7th tile fence, 8 & 9 gates
        (*fenceTexture[i]).loadFromFile("./gameObjects/assets/shaded_fence.png");
        (*fenceSprite[i]).setTexture(*fenceTexture[i]);
        (*fenceSprite[i]).setPosition(80*i,160); //(x,2)
        this->window->draw(*fenceSprite[i]);
        }
    //gates
        //left
        sf::Texture leftGateTexture;
        sf::Sprite leftGateSprite;
        leftGateTexture.loadFromFile("./gameObjects/assets/shaded_fence_gate_left.png");
        leftGateSprite.setTexture(leftGateTexture);
        leftGateSprite.setPosition(640,0); //(7,2)
        this->window->draw(leftGateSprite);
        //right
        sf::Texture rightGateTexture;
        sf::Sprite rightGateSprite;
        rightGateTexture.loadFromFile("./gameObjects/assets/shaded_fence_gate_right.png");
        rightGateSprite.setTexture(leftGateTexture);
        rightGateSprite.setPosition(720,0); //(8,2)
        this->window->draw(rightGateSprite);
    //plots
        sf::Texture* plotTexture[9];
        sf::Sprite* plotSprite[9];
        int plotNumber = 0;
        for (int i = 0; i < 3; i++) { //for 3 horizontal
            for (int j = 0; i < 3; i++) { //for 3 vertical
            (*plotTexture[plotNumber]).loadFromFile("./gameObjects/assets/empty_tile.png");
            (*plotSprite[plotNumber]).setTexture(*plotTexture[plotNumber]);
            (*plotSprite[plotNumber]).setPosition(240+160*i,400+160*j); //(x,2)
            this->window->draw(*plotSprite[plotNumber]);
            plotNumber = plotNumber + 1;
            }
        }
}

void gameEngine::render() {
    this->window->clear(sf::Color(0,255,0,255)); //clear old stuff
    setBaseScreen();
    //updates I guess
    this->window->display(); //display new stuff
}

const bool gameEngine::running() const { return this->window->isOpen(); }; //isOpen() returns bool for if window is open, SFML built in function