#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <string>

// Forward declare SFML types to avoid dependency issues for now
// (Replace these with #include <SFML/Graphics.hpp> later)
namespace sf {
    class Texture;
    class Sprite;
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
