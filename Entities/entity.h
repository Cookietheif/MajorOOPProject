#include "Entity.h"
#include <iostream>


Entity::Entity()
    : entity_ID(0),
      entity_Name("Unnamed Entity"),
      texture(nullptr),
      sprite(nullptr)
{
    std::cout << "Entity created: " << entity_Name << std::endl;
}


Entity::~Entity() {
    std::cout << "Entity destroyed: " << entity_Name << std::endl;
    // If you later allocate texture/sprite dynamically, delete them here
    // Example:
    // delete texture;
    // delete sprite;
}


void Entity::draw() {
    // Derived classes can override this to draw their sprite
}
