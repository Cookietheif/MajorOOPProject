#ifndef LITTLEDUDES_H
#define LITTLEDUDES_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

class Sprites
{
    public:
    int count;
    sf::Texture* textureMatrix;
    sf::Sprite* spriteMatrix;

    void setSprites();

    Sprites();
    ~Sprites();
};

#endif