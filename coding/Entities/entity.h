#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

// Base Entity Class

class Entity {
protected:
    int entity_ID;                // Unique ID for each entity
    std::string entity_Name;      // Entity name or label

    // --- Graphics placeholders (to be implemented later with SFML) ---
    sf::Texture* texture;         // Placeholder for sprite texture
    sf::Sprite sprite;           // Placeholder for sprite itself

public:
    // --- Constructors & Destructor ---
    Entity();                     // Default constructor
    virtual ~Entity();            // Virtual destructor for inheritance

    // --- Accessors ---
    std::string getName() const { return entity_Name; }
    int getID() const { return entity_ID; }

    virtual void draw() = 0;                    // Pure virtual as placeholder for drawing later
};

#endif
