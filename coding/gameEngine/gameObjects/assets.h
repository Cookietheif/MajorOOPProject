#ifndef ASSETS_H
#define ASSETS_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "gameState.h"

//use of "_" instead of snake capitalisation for textures, I felt like it

class assets {
public:
    assets(); //constructor loads all textures and sets all sprites
    ~assets();
    void setText(GameState gameState, sf::RenderWindow& window); //gamestate passed so that money can be getted
    void setBaseScreen(GameState gameState, sf::RenderWindow& window);
    void setSeeds(sf::RenderWindow& window);
    void maintainPlots(GameState gameState, sf::RenderWindow& window);
    sf::Texture dereferenceSeed(int seedNum);
    void setSeason(GameState gameState, sf::RenderWindow& window);

    //default screen function


    //text
    sf::Font font;
    sf::Text moneyText;

    //assets
    sf::Sprite* plotSprite;

    sf::Texture carrot_seed_bordered_texture; sf::Sprite carrot_seed_bordered_sprite;
    sf::Texture carrot_seed_texture; sf::Sprite carrot_seed_sprite;
    sf::Texture carrot_tile_grown_texture; sf::Sprite carrot_tile_grown_sprite;
    sf::Texture carrot_tile_texture; sf::Sprite carrot_tile_sprite;

    sf::Texture chicken_bordered_texture; sf::Sprite chicken_bordered_sprite;
    sf::Texture chicken_harvestable_texture; sf::Sprite chicken_harvestable_sprite;
    sf::Texture chicken_tile_texture; sf::Sprite chicken_tile_sprite;
    sf::Texture chicken_texture; sf::Sprite chicken_sprite;

    sf::Texture coin_texture; sf::Sprite coin_sprite;

    sf::Texture cow_bordered_texture; sf::Sprite cow_bordered_sprite;
    sf::Texture cow_harvestable_texture; sf::Sprite cow_harvestable_sprite;
    sf::Texture cow_tile_texture; sf::Sprite cow_tile_sprite;
    sf::Texture cow_texture; sf::Sprite cow_sprite;

    sf::Texture dead_tree_texture; sf::Sprite dead_tree_sprite;

    sf::Texture empty_tile_texture; sf::Sprite empty_tile_sprite;

    sf::Texture pig_bordered_texture; sf::Sprite pig_bordered_sprite;
    sf::Texture pig_tile_texture; sf::Sprite pig_tile_sprite;
    sf::Texture pig_texture; sf::Sprite pig_sprite;

    sf::Texture potato_seed_bordered_texture; sf::Sprite potato_seed_bordered_sprite;
    sf::Texture potato_seed_texture; sf::Sprite potato_seed_sprite;
    sf::Texture potato_tile_grown_texture; sf::Sprite potato_tile_grown_sprite;
    sf::Texture potato_tile_texture; sf::Sprite potato_tile_sprite;

    sf::Texture rain_texture; sf::Sprite rain_sprite;

    sf::Texture shaded_fence_gate_left_texture; sf::Sprite shaded_fence_gate_left_sprite;
    sf::Texture shaded_fence_gate_right_texture; sf::Sprite shaded_fence_gate_right_sprite;
    sf::Texture shaded_fence_texture; sf::Sprite shaded_fence_sprite[7];

    sf::Texture strawberry_seed_bordered_texture; sf::Sprite strawberry_seed_bordered_sprite;
    sf::Texture strawberry_seed_texture; sf::Sprite strawberry_seed_sprite;
    sf::Texture strawberry_tile_grown_texture; sf::Sprite strawberry_tile_grown_sprite;
    sf::Texture strawberry_tile_texture; sf::Sprite strawberry_tile_sprite;

    sf::Texture sun1_texture; sf::Sprite sun1_sprite;
    sf::Texture sun2_texture; sf::Sprite sun2_sprite;
};
#endif