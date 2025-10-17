#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include "coding/Entities/entity.h"

Entity::Entity()
    : entity_ID(0),
      entity_Name("Unnamed Entity"),
{
    texture.loadFromFile(); //idk how to do this bit so that works for all.
    sprite.setTexture(*texture);
    std::cout << "Entity created: " << entity_Name << std::endl;
}


Entity::~Entity() {
    std::cout << "Entity destroyed: " << entity_Name << std::endl;
    // If you later allocate texture/sprite dynamically, delete them here
    // Example:
    // delete texture;
    // delete sprite;
}
