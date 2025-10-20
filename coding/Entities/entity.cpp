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

// Base Entity Class

class Entity {
protected:
    int entity_ID;                // Unique ID for each entity
    std::string entity_Name;      // Entity name or label

    // --- Graphics placeholders (to be implemented later with SFML) ---
    sf::Texture* texture;         // Placeholder for sprite texture
    sf::Sprite* sprite;           // Placeholder for sprite itself

public:
    // --- Constructors & Destructor ---
    Entity();                     // Default constructor
    virtual ~Entity();            // Virtual destructor for inheritance

    // --- Accessors ---
    std::string getName() const { return entity_Name; }
    int getID() const { return entity_ID; }

    // --- Virtual methods (optional placeholders for future use) ---
    virtual void draw();                    // Placeholder for rendering
};

#endif
