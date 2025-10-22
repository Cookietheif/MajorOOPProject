#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "gameState.h"
#include "assets.h"
//I apologise for the following include list
#include "carrot.h" 
#include "chicken.h" 
#include "cow.h" 
#include "pig.h" 
#include "potato.h" 
#include "strawberry.h" 

#include "gameEngine.h"

gameEngine::gameEngine(assets& assets, GameState& gameState) {
    gameEngine::initialiseVariables();
    gameEngine::initialiseWindow(assets, gameState);
};


//private functions
void gameEngine::initialiseVariables() {
    this->window = nullptr;
};
void gameEngine::initialiseWindow(assets& assets, GameState& gameState) {
    this->window = new sf::RenderWindow(sf::VideoMode(720, 960), "Farming Simulator", sf::Style::Titlebar | sf::Style::Close); //720=9 (tiles) *16 (pixels) *5 (scale for window size), titled Farming Simulator with close button, 9x12 window
    this->window->setFramerateLimit(60); //frame limit
    this->window->clear(sf::Color(0,255,0,255)); //set background

    //default screen
    assets.setBaseScreen(gameState, *this->window);
};

//public functions
// constructor

//game function
void gameEngine::pollEvents() {while (this->window->pollEvent(gameEvent)) //loop for game again - constant checking for game end
    if (gameEvent.type == sf::Event::Closed || (gameEvent.type == sf::Event::KeyPressed && gameEvent.key.code == sf::Keyboard::Escape)) { //for the record, switch cases super recommended here, I just don't like them
        this->window->close(); 
    };
};

void gameEngine::updateMousePositions() {
    this->mousePositionWindow = sf::Mouse::getPosition(*this->window);
}

void gameEngine::update(assets& assets, GameState& gameState) {
    this->pollEvents();

    // Mouse position
    this->updateMousePositions();

    //check for shop hover for prettiness
    if ((this->mousePositionWindow.y) <= 80 && (this->mousePositionWindow.y >= 0)) { //in top row
        //what tile hovering bordered call
        if (this->mousePositionWindow.x > 85 && this->mousePositionWindow.x < 160) { //strawberry, 1
            assets.strawberry_seed_bordered_sprite.setPosition(80,0);
            this->window->draw(assets.strawberry_seed_bordered_sprite);
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {gameState.setSeedSelected(1);}
        } else if (this->mousePositionWindow.x > 165 && this->mousePositionWindow.x < 235) { //carrot 2
            assets.carrot_seed_bordered_sprite.setPosition(160,0);
            this->window->draw(assets.carrot_seed_bordered_sprite);
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {gameState.setSeedSelected(2);}
        } else if (this->mousePositionWindow.x > 245 && this->mousePositionWindow.x < 315) { //potato 3
            assets.potato_seed_bordered_sprite.setPosition(240,0);
            this->window->draw(assets.potato_seed_bordered_sprite);
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {gameState.setSeedSelected(3);}
        } else if (this->mousePositionWindow.x > 325 && this->mousePositionWindow.x < 395) { //cow 4
            assets.cow_bordered_sprite.setPosition(320,0);
            this->window->draw(assets.cow_bordered_sprite);
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {gameState.setSeedSelected(4);}
        } else if (this->mousePositionWindow.x > 405 && this->mousePositionWindow.x < 475) { //pig 5
            assets.pig_bordered_sprite.setPosition(400,0);
            this->window->draw(assets.pig_bordered_sprite);
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {gameState.setSeedSelected(5);}
        } else if (this->mousePositionWindow.x > 485 && this->mousePositionWindow.x < 555) { //chicken 6
            assets.chicken_bordered_sprite.setPosition(480,0);
            this->window->draw(assets.chicken_bordered_sprite);
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {gameState.setSeedSelected(6);}
        } else { //reset to no bordered but keep what is selected bordered
            assets.setSeeds(*this->window);

            switch (gameState.getSeedSelected()) {
                case 1: //strawberry 1
                    assets.strawberry_seed_bordered_sprite.setPosition(80,0);
                    this->window->draw(assets.strawberry_seed_bordered_sprite);
                    break;
                case 2: //carrot 2
                     assets.carrot_seed_bordered_sprite.setPosition(160,0);
                    this->window->draw(assets.carrot_seed_bordered_sprite);
                    break;
                case 3: //potato 3
                    assets.potato_seed_bordered_sprite.setPosition(240,0);
                    this->window->draw(assets.potato_seed_bordered_sprite);
                    break;
                case 4: //cow 4
                    assets.cow_bordered_sprite.setPosition(320,0);
                    this->window->draw(assets.cow_bordered_sprite);
                    break;
                case 5: //pig 5
                    assets.pig_bordered_sprite.setPosition(400,0);
                    this->window->draw(assets.pig_bordered_sprite);
                    break;
                case 6: //chicken 6
                    assets.chicken_bordered_sprite.setPosition(400,0);
                    this->window->draw(assets.chicken_bordered_sprite);
                    break;
            }
        }
    }

    if (gameEvent.type == sf::Event::MouseButtonPressed) {
            //game function 
        if (gameEvent.mouseButton.button == sf::Mouse::Left){ // set plots
            int plotNumber = 0;
            if (gameState.getSeedSelected() > 0 && gameState.getSeedSelected() < 6) { //check if seed is selected then check if sufficient funds then set plots
                for (int i = 0; i < 3; i++) { //for 3 horizontal
                    for (int j = 0; j < 3; j++) { //for 3 vertical
                        plotNumber = plotNumber + 1;
                        if (((mousePositionWindow.x >= 240+160*i) && (mousePositionWindow.x <= 80+ 240+160*i))&&((mousePositionWindow.y >= 400+160*j) && mousePositionWindow.y <= 80+400+160*j)) {
                            gameState.buyEntity(plotNumber, gameState.getSeedSelected()); //plot number and pointer to entity
                            (assets.plotSprite[plotNumber]).setTexture(assets.dereferenceSeed(gameState.getSeedSelected()));
                            this->window->draw(assets.plotSprite[plotNumber]);
                        }
                    }
                }
            }
        } 

        if (gameEvent.mouseButton.button == sf::Mouse::Right){ // sell
            int plotNumber = 0;
            if (gameState.getSeedSelected() > 0) { //check if seed is selected then check if sufficient funds then set plots
                for (int i = 0; i < 3; i++) { //for 3 horizontal
                    for (int j = 0; j < 3; j++) { //for 3 vertical
                        plotNumber = plotNumber + 1;
                        if (((mousePositionWindow.x >= 240+160*i) && (mousePositionWindow.x <= 80+ 240+160*i))&&((mousePositionWindow.y >= 400+160*j) && mousePositionWindow.y <= 80+400+160*j)) {
                        gameState.sellEntity(plotNumber); //plot number
                        (assets.plotSprite[plotNumber]).setTexture(assets.empty_tile_texture);
                        this->window->draw(assets.plotSprite[plotNumber]);
                        assets.setText(gameState, *this->window);
                        }
                    }
                }
            }
        }
    }
    if (gameEvent.type == sf::Event::KeyPressed) {
        if (gameEvent.key.code == sf::Keyboard::Space) {//progress turns
            gameState.nextTurn();
            assets.maintainPlots(gameState, *this->window);
            assets.setSeason(gameState, *this->window);
            std::cout << "It is turn: " << gameState.getTurnNumber() << "\n";
            if (gameState.getTurnNumber() > 12) {
                std::cout << "Your score was: " << gameState.getMoney() << "Well done!" << "\n";
                gameEngine::~gameEngine();
            }
        }
    }
}

//render/visualise/display game function

void gameEngine::render() {
    this->window->display(); //display new stuff
}

const bool gameEngine::running() const {return this->window->isOpen();}; //isOpen() returns bool for if window is open, SFML built in function

//destructor
gameEngine::~gameEngine() { //deconstructor ensures freeing space and closes window just in case
    if (this->running()) {this->window->close();}
    delete this->window;
};
