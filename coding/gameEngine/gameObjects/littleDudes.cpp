#include "littleDudes.h"



Sprites::Sprites() {
    count = 20; //want to make adjustable based upon how many entities but maybe added functionality, not yet
    this->spriteMatrix = new sf::Sprite[count]; 
    this->textureMatrix = new sf::Texture[count];
    setSprites();
}

void Sprites::setSprites() {for (int i=0; i<count; i++) {
    textureMatrix[i].loadFromFile();
    spriteMatrix[i].setTexture(textureMatrix[i]);

};};

Sprites::~Sprites() {delete this->spriteMatrix;};