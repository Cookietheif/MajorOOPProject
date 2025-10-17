#include "Entity.h"
#include <iostream>
#include <SFML/Graphics.hpp>


Entity::Entity()
    : entity_ID(0),
      entity_Name("Unnamed Entity"),
{
    texture.loadFromFile();
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
