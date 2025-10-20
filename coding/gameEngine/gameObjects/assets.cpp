#include "./assets.h"
#include "./gameState/gameState.h"
#include <string>
#include "assets.h"

assets::assets() {
//text font
font.loadFromFile("./assets/font.ttf");

//load and assign assets
carrot_seed_bordered_texture.loadFromFile("./assets/carrot_seed_bordered.png");
carrot_seed_bordered_sprite.setTexture(carrot_seed_bordered_texture);

carrot_seed_texture.loadFromFile("./assets/carrot_seed.png");
carrot_seed_sprite.setTexture(carrot_seed_texture);

carrot_tile_grown_texture.loadFromFile("./assets/carrot_tile_grown.png");
carrot_tile_grown_sprite.setTexture(carrot_tile_grown_texture);

carrot_tile_texture.loadFromFile("./assets/carrot_tile.png");
carrot_tile_sprite.setTexture(carrot_tile_texture);

chicken_bordered_texture.loadFromFile("./assets/chicken_bordered.png");
chicken_bordered_sprite.setTexture(chicken_bordered_texture);

chicken_tile_texture.loadFromFile("./assets/chicken_tile.png");
chicken_tile_sprite.setTexture(chicken_tile_texture);

chicken_texture.loadFromFile("./assets/chicken.png");
chicken_sprite.setTexture(chicken_texture);

coin_texture.loadFromFile("./assets/coin.png");
coin_sprite.setTexture(coin_texture);

cow_bordered_texture.loadFromFile("./assets/cow_bordered.png");
cow_bordered_sprite.setTexture(cow_bordered_texture);

cow_tile_texture.loadFromFile("./assets/cow_tile.png");
cow_tile_sprite.setTexture(cow_tile_texture);

cow_texture.loadFromFile("./assets/cow.png");
cow_sprite.setTexture(cow_texture);

dead_tree_texture.loadFromFile("./assets/dead_tree.png");
dead_tree_sprite.setTexture(dead_tree_texture);

empty_tile_texture.loadFromFile("./assets/empty_tile.png");
empty_tile_sprite.setTexture(empty_tile_texture);

pig_bordered_texture.loadFromFile("./assets/pig_bordered.png");
pig_bordered_sprite.setTexture(pig_bordered_texture);

pig_tile_texture.loadFromFile("./assets/pig_tile.png");
pig_tile_sprite.setTexture(pig_tile_texture);

pig_texture.loadFromFile("./assets/pig.png");
pig_sprite.setTexture(pig_texture);

potato_seed_bordered_texture.loadFromFile("./assets/potato_seed_bordered.png");
potato_seed_bordered_sprite.setTexture(potato_seed_bordered_texture);

potato_seed_texture.loadFromFile("./assets/potato_seed.png");
potato_seed_sprite.setTexture(potato_seed_texture);

potato_tile_grown_texture.loadFromFile("./assets/potato_tile_grown.png");
potato_tile_grown_sprite.setTexture(potato_tile_grown_texture);

potato_tile_texture.loadFromFile("./assets/potato_tile.png");
potato_tile_sprite.setTexture(potato_tile_texture);

rain_texture.loadFromFile("./assets/rain.png");
rain_sprite.setTexture(rain_texture);

shaded_fence_gate_left_texture.loadFromFile("./assets/shaded_fence_gate_left.png");
shaded_fence_gate_left_sprite.setTexture(shaded_fence_gate_left_texture);

shaded_fence_gate_right_texture.loadFromFile("./assets/shaded_fence_gate_right.png");
shaded_fence_gate_right_sprite.setTexture(shaded_fence_gate_right_texture);

    shaded_fence_texture.loadFromFile("./assets/shaded_fence.png");
for (int i = 0; i < 7; i++) { //from 1st to 7th tile fence, 8 & 9 gates
    (shaded_fence_sprite[i]).setTexture(shaded_fence_texture);
}

strawberry_seed_bordered_texture.loadFromFile("./assets/strawberry_seed_bordered.png");
strawberry_seed_bordered_sprite.setTexture(strawberry_seed_bordered_texture);

strawberry_seed_texture.loadFromFile("./assets/strawberry_seed.png");
strawberry_seed_sprite.setTexture(strawberry_seed_texture);

strawberry_tile_grown_texture.loadFromFile("./assets/strawberry_tile_grown.png");
strawberry_tile_grown_sprite.setTexture(strawberry_tile_grown_texture);

strawberry_tile_texture.loadFromFile("./assets/strawberry_tile.png");
strawberry_tile_sprite.setTexture(strawberry_tile_texture);

sun1_texture.loadFromFile("./assets/sun1.png");
sun1_sprite.setTexture(sun1_texture);

sun2_texture.loadFromFile("./assets/sun2.png");
sun2_sprite.setTexture(sun2_texture);
};

assets::~assets() {};

void assets::setTextures(GameState gameState) {
moneyText.setFont(font);
moneyText.setFillColor(sf::Color::Black);
moneyText.setPosition(740,30);
moneyText.setCharacterSize(1); //text size, mess around and see
std::string moneyCount = std::to_string(gameState.getMoney()); //gets int from gamestate and converts to string for display
moneyText.setString(moneyCount);
}

void assets::setBaseScreen(GameState gameState, sf::RenderWindow& window) {
    //season
    switch (gameState.getSeason())
    {
    case 1: //spring
    sun1_sprite.setPosition(0,0); //(0,0)
    window.draw(sun1_sprite);
    case 2: //winter
    rain_sprite.setPosition(0,0); //(0,0)
    window.draw(rain_sprite);
    case 3: //autumn
    dead_tree_sprite.setPosition(0,0); //(0,0)
    window.draw(dead_tree_sprite);
    case 4: //summer
    sun2_sprite.setPosition(0,0); //(0,0)
    window.draw(sun2_sprite);
    };
    //shoppable
    
        //seeds
            //Strawberry
            strawberry_seed_sprite.setPosition(80,0); //(1,0)
            window.draw(strawberry_seed_sprite);
            //Carrot
            carrot_seed_sprite.setPosition(160,0); //(2,0)
            window.draw(carrot_seed_sprite);
            //potato
            potato_seed_sprite.setPosition(240,0); //(3,0)
            window.draw(potato_seed_sprite);
        //animals
            //cow
            cow_sprite.setPosition(320,0); //(4,0)
            window.draw(cow_sprite);
            //pig
            pig_sprite.setPosition(400,0); //(5,0)
            window.draw(pig_sprite);
            //chicken
            chicken_sprite.setPosition(480,0); //(6,0)
            window.draw(chicken_sprite);
    //coin symbol //probably move this bit to other function
    coin_sprite.setPosition(560,0); //(7,0)
    window.draw(coin_sprite);
    //fences
        for (int i = 0; i < 7; i++) { //from 1st to 7th tile fence, 8 & 9 gates
        (shaded_fence_sprite[i]).setPosition(80*i,160); //(x,2)
        window.draw(shaded_fence_sprite[i]);
        }
    //gates
        //left
        shaded_fence_gate_left_sprite.setPosition(640,0); //(7,2)
        window.draw(shaded_fence_gate_left_sprite);
        //right
        shaded_fence_gate_right_sprite.setPosition(720,0); //(8,2)
        window.draw(shaded_fence_gate_right_sprite);
    //plots
        sf::Texture* plotTexture[9];
        sf::Sprite* plotSprite[9];
        int plotNumber = 0;
        for (int i = 0; i < 3; i++) { //for 3 horizontal
            for (int j = 0; i < 3; i++) { //for 3 vertical
            (*plotTexture[plotNumber]).loadFromFile("./gameObjects/assets/empty_tile.png");
            (*plotSprite[plotNumber]).setTexture(*plotTexture[plotNumber]);
            (*plotSprite[plotNumber]).setPosition(240+160*i,400+160*j); //(x,2)
            this->window->draw(*plotSprite[plotNumber]);
            plotNumber = plotNumber + 1;
            }
        }
}

void assets::drawAll() {}