#ifndef CARROT_H
#define CARROT_H

#include <SFML/Graphics.hpp>

#include "./crops.h"

class Carrot : public Crops {
public:
    sf::Texture seedTexture;
    sf::Texture ungrownTexture;
    sf::Texture grownTexture;
    sf::Sprite seedSprite;
    sf::Sprite ungrownSprite;
    sf::Sprite grownSprite;
    
    Carrot();
    virtual ~Carrot();

    void initialiseAsset();
    
    int sellCrop() override;       
    void seasonalMod(const gameEngine& engine) override;
   
};

#endif 
 