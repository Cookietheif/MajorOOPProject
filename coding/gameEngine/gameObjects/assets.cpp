#include "assets.h"
#include "gameState.h"
#include <string>
#include <iostream>

assets::assets() {
//plots
    plotSprite = new sf::Sprite[10];
    for (int i = 0; i < 10; i++) plotSprite[i].setScale(5.f, 5.f);
//textures
    if (!carrot_seed_bordered_texture.loadFromFile("coding/gameEngine/gameObjects/assets/carrot_seed_bordered.png")) std::cerr << "Failed to load carrot_seed_bordered.png\n";
    carrot_seed_bordered_sprite.setTexture(carrot_seed_bordered_texture);
    carrot_seed_bordered_sprite.setScale(5.f,5.f);

    if (!carrot_seed_texture.loadFromFile("coding/gameEngine/gameObjects/assets/carrot_seed.png")) std::cerr << "Failed to load carrot_seed.png\n";
    carrot_seed_sprite.setTexture(carrot_seed_texture);
    carrot_seed_sprite.setScale(5.f,5.f);

    if (!carrot_tile_grown_texture.loadFromFile("coding/gameEngine/gameObjects/assets/carrot_tile_grown.png")) std::cerr << "Failed to load carrot_tile_grown.png\n";
    carrot_tile_grown_sprite.setTexture(carrot_tile_grown_texture);
    carrot_tile_grown_sprite.setScale(5.f,5.f);

    if (!carrot_tile_texture.loadFromFile("coding/gameEngine/gameObjects/assets/carrot_tile.png")) std::cerr << "Failed to load carrot_tile.png\n";
    carrot_tile_sprite.setTexture(carrot_tile_texture);
    carrot_tile_sprite.setScale(5.f,5.f);

    if (!chicken_bordered_texture.loadFromFile("coding/gameEngine/gameObjects/assets/chicken_bordered.png")) std::cerr << "Failed to load chicken_bordered.png\n";
    chicken_bordered_sprite.setTexture(chicken_bordered_texture);
    chicken_bordered_sprite.setScale(5.f,5.f);

    if (!chicken_harvestable_texture.loadFromFile("coding/gameEngine/gameObjects/assets/chicken_harvestable.png")) std::cerr << "Failed to load chicken_harvestable.png\n";
    chicken_harvestable_sprite.setTexture(chicken_harvestable_texture);
    chicken_harvestable_sprite.setScale(5.f,5.f);

    if (!chicken_tile_texture.loadFromFile("coding/gameEngine/gameObjects/assets/chicken_tile.png")) std::cerr << "Failed to load chicken_tile.png\n";
    chicken_tile_sprite.setTexture(chicken_tile_texture);
    chicken_tile_sprite.setScale(5.f,5.f);

    if (!chicken_texture.loadFromFile("coding/gameEngine/gameObjects/assets/chicken.png")) std::cerr << "Failed to load chicken.png\n";
    chicken_sprite.setTexture(chicken_texture);
    chicken_sprite.setScale(5.f,5.f);
    
    if (!coin_texture.loadFromFile("coding/gameEngine/gameObjects/assets/coin.png")) std::cerr << "Failed to load coin.png\n";
    coin_sprite.setTexture(coin_texture);
    coin_sprite.setScale(5.f,5.f);

    if (!cow_bordered_texture.loadFromFile("coding/gameEngine/gameObjects/assets/cow_bordered.png")) std::cerr << "Failed to load cow_bordered.png\n";
    cow_bordered_sprite.setTexture(cow_bordered_texture);
    cow_bordered_sprite.setScale(5.f,5.f);

    if (!cow_harvestable_texture.loadFromFile("coding/gameEngine/gameObjects/assets/cow_harvestable.png")) std::cerr << "Failed to load cow_harvestable.png\n";
    cow_harvestable_sprite.setTexture(cow_harvestable_texture);
    cow_harvestable_sprite.setScale(5.f,5.f);

    if (!cow_tile_texture.loadFromFile("coding/gameEngine/gameObjects/assets/cow_tile.png")) std::cerr << "Failed to load cow_tile.png\n";
    cow_tile_sprite.setTexture(cow_tile_texture);
    cow_tile_sprite.setScale(5.f,5.f);

    if (!cow_texture.loadFromFile("coding/gameEngine/gameObjects/assets/cow.png")) std::cerr << "Failed to load cow.png\n";
    cow_sprite.setTexture(cow_texture);
    cow_sprite.setScale(5.f,5.f);

    if (!dead_tree_texture.loadFromFile("coding/gameEngine/gameObjects/assets/dead_tree.png")) std::cerr << "Failed to load dead_tree.png\n";
    dead_tree_sprite.setTexture(dead_tree_texture);
    dead_tree_sprite.setScale(5.f,5.f);

    if (!empty_tile_texture.loadFromFile("coding/gameEngine/gameObjects/assets/empty_tile.png")) std::cerr << "Failed to load empty_tile.png\n";
    empty_tile_sprite.setTexture(empty_tile_texture);
    empty_tile_sprite.setScale(5.f,5.f);

    if (!pig_bordered_texture.loadFromFile("coding/gameEngine/gameObjects/assets/pig_bordered.png")) std::cerr << "Failed to load pig_bordered.png\n";
    pig_bordered_sprite.setTexture(pig_bordered_texture);
    pig_bordered_sprite.setScale(5.f,5.f);

    if (!pig_tile_texture.loadFromFile("coding/gameEngine/gameObjects/assets/pig_tile.png")) std::cerr << "Failed to load pig_tile.png\n";
    pig_tile_sprite.setTexture(pig_tile_texture);
    pig_tile_sprite.setScale(5.f,5.f);

    if (!pig_texture.loadFromFile("coding/gameEngine/gameObjects/assets/pig.png")) std::cerr << "Failed to load pig.png\n";
    pig_sprite.setTexture(pig_texture);
    pig_sprite.setScale(5.f,5.f);

    if (!potato_seed_bordered_texture.loadFromFile("coding/gameEngine/gameObjects/assets/potato_seed_bordered.png")) std::cerr << "Failed to load potato_seed_bordered.png\n";
    potato_seed_bordered_sprite.setTexture(potato_seed_bordered_texture);
    potato_seed_bordered_sprite.setScale(5.f,5.f);

    if (!potato_seed_texture.loadFromFile("coding/gameEngine/gameObjects/assets/potato_seed.png")) std::cerr << "Failed to load potato_seed.png\n";
    potato_seed_sprite.setTexture(potato_seed_texture);
    potato_seed_sprite.setScale(5.f,5.f);

    if (!potato_tile_grown_texture.loadFromFile("coding/gameEngine/gameObjects/assets/potato_tile_grown.png")) std::cerr << "Failed to load potato_tile_grown.png\n";
    potato_tile_grown_sprite.setTexture(potato_tile_grown_texture);
    potato_tile_grown_sprite.setScale(5.f,5.f);

    if (!potato_tile_texture.loadFromFile("coding/gameEngine/gameObjects/assets/potato_tile.png")) std::cerr << "Failed to load potato_tile.png\n";
    potato_tile_sprite.setTexture(potato_tile_texture);
    potato_tile_sprite.setScale(5.f,5.f);

    if (!rain_texture.loadFromFile("coding/gameEngine/gameObjects/assets/rain.png")) std::cerr << "Failed to load rain.png\n";
    rain_sprite.setTexture(rain_texture);
    rain_sprite.setScale(5.f,5.f);

    if (!shaded_fence_gate_left_texture.loadFromFile("coding/gameEngine/gameObjects/assets/shaded_fence_gate_left.png")) std::cerr << "Failed to load shaded_fence_gate_left.png\n";
    shaded_fence_gate_left_sprite.setTexture(shaded_fence_gate_left_texture);
    shaded_fence_gate_left_sprite.setScale(5.f,5.f);

    if (!shaded_fence_gate_right_texture.loadFromFile("coding/gameEngine/gameObjects/assets/shaded_fence_gate_right.png")) std::cerr << "Failed to load shaded_fence_gate_right.png\n";
    shaded_fence_gate_right_sprite.setTexture(shaded_fence_gate_right_texture);
    shaded_fence_gate_right_sprite.setScale(5.f,5.f);

    if (!shaded_fence_texture.loadFromFile("coding/gameEngine/gameObjects/assets/shaded_fence.png")) std::cerr << "Failed to load shaded_fence.png\n";
    for (int i = 0; i < 8; i++) {
        shaded_fence_sprite[i].setTexture(shaded_fence_texture);
        shaded_fence_sprite[i].setScale(5.f,5.f);
    }

    if (!strawberry_seed_bordered_texture.loadFromFile("coding/gameEngine/gameObjects/assets/strawberry_seed_bordered.png")) std::cerr << "Failed to load strawberry_seed_bordered.png\n";
    strawberry_seed_bordered_sprite.setTexture(strawberry_seed_bordered_texture);
    strawberry_seed_bordered_sprite.setScale(5.f,5.f);

    if (!strawberry_seed_texture.loadFromFile("coding/gameEngine/gameObjects/assets/strawberry_seed.png")) std::cerr << "Failed to load strawberry_seed.png\n";
    strawberry_seed_sprite.setTexture(strawberry_seed_texture);
    strawberry_seed_sprite.setScale(5.f,5.f);

    if (!strawberry_tile_grown_texture.loadFromFile("coding/gameEngine/gameObjects/assets/strawberry_tile_grown.png")) std::cerr << "Failed to load strawberry_tile_grown.png\n";
    strawberry_tile_grown_sprite.setTexture(strawberry_tile_grown_texture);
    strawberry_tile_grown_sprite.setScale(5.f,5.f);

    if (!strawberry_tile_texture.loadFromFile("coding/gameEngine/gameObjects/assets/strawberry_tile.png")) std::cerr << "Failed to load strawberry_tile.png\n";
    strawberry_tile_sprite.setTexture(strawberry_tile_texture);
    strawberry_tile_sprite.setScale(5.f,5.f);

    if (!sun1_texture.loadFromFile("coding/gameEngine/gameObjects/assets/sun1.png")) std::cerr << "Failed to load sun1.png\n";
    sun1_sprite.setTexture(sun1_texture);
    sun1_sprite.setScale(5.f,5.f);

    if (!sun2_texture.loadFromFile("coding/gameEngine/gameObjects/assets/sun2.png")) std::cerr << "Failed to load sun2.png\n";
    sun2_sprite.setTexture(sun2_texture);
    sun2_sprite.setScale(5.f,5.f);
}


assets::~assets() {
};

void assets::setText(GameState& gameState) {
std::cout << "Your money is" << gameState.getMoney() << "\n";
}

void assets::setSeason(GameState& gameState, sf::RenderWindow& window) {
        //season
    switch (gameState.getSeason())
    {
    case 1: //spring
    sun1_sprite.setPosition(0,0); //(0,0)
    window.draw(sun1_sprite);
    break;
    case 2: //winter
    rain_sprite.setPosition(0,0); //(0,0)
    window.draw(rain_sprite);
    break;
    case 3: //autumn
    dead_tree_sprite.setPosition(0,0); //(0,0)
    window.draw(dead_tree_sprite);
    break;
    case 4: //summer
    sun2_sprite.setPosition(0,0); //(0,0)
    window.draw(sun2_sprite);
    break;
    };
}

void assets::setBaseScreen(GameState& gameState, sf::RenderWindow& window) {
    setSeason(gameState, window);
    setSeeds(window);
    //coin symbol
    coin_sprite.setPosition(560,0); //(7,0)
    window.draw(coin_sprite);
    //fences
        for (int i = 0; i < 7; i++) { //from 1st to 7th tile fence, 8 & 9 gates
        (shaded_fence_sprite[i]).setPosition(80*i,160); //(x,2)
        window.draw(shaded_fence_sprite[i]);
        }
    //gates
        //left
        shaded_fence_gate_left_sprite.setPosition(560,160); //(7,2)
        window.draw(shaded_fence_gate_left_sprite);
        //right
        shaded_fence_gate_right_sprite.setPosition(640,160); //(8,2)
        window.draw(shaded_fence_gate_right_sprite);
    //plots
        int plotNumber = 0;
        for (int i = 0; i < 3; i++) { //for 3 horizontal
            for (int j = 0; j < 3; j++) { //for 3 vertical
            plotNumber = plotNumber + 1;
            (plotSprite[plotNumber]).setTexture(empty_tile_texture);
            (plotSprite[plotNumber]).setPosition(160+160*i,400+160*j); //(x,2)
            window.draw(plotSprite[plotNumber]);
            }
        }
}

void assets::maintainPlots(GameState& gameState, sf::RenderWindow& window) { //check if grown, update when grown
    Entity* plots[9] = { gameState.getPlot(1), gameState.getPlot(2), gameState.getPlot(3), gameState.getPlot(4), gameState.getPlot(5), gameState.getPlot(6), gameState.getPlot(7), gameState.getPlot(8), gameState.getPlot(9) }; ;
    std::cerr << "owwie";
    for (int i = 0; i < 9; i++) {
                std::cerr << "shining " << i << std::endl;
            switch (plots[i]->getCurrentID()){
            case 1:
            std::cerr << "one " << i << std::endl;
                break;
            case 2:
            std::cerr << "two " << i << std::endl;
                break;
            case 3:
            std::cerr << "three" << i << std::endl;
                plotSprite[i].setTexture(carrot_tile_texture);
                window.draw(plotSprite[i]);
                break;
            case 4:
            std::cerr << "crash " << i << std::endl;
                plotSprite[i].setTexture(carrot_tile_grown_texture);
                window.draw(plotSprite[i]);
                break;
            case 5: 
                plotSprite[i].setTexture(potato_tile_texture);
                window.draw(plotSprite[i]);
                break;
            case 6:
                plotSprite[i].setTexture(potato_tile_grown_texture);
                window.draw(plotSprite[i]);
                break;
            case 7:
                plotSprite[i].setTexture(cow_tile_texture);
                window.draw(plotSprite[i]);
                break;
            case 8:
                plotSprite[i].setTexture(cow_harvestable_texture);
                window.draw(plotSprite[i]);
                break;
            case 9:
                plotSprite[i].setTexture(pig_tile_texture);
                window.draw(plotSprite[i]);
            break;
            case 11:
                plotSprite[i].setTexture(chicken_tile_texture);
                window.draw(plotSprite[i]);
                break;
            case 12:
                plotSprite[i].setTexture(chicken_harvestable_texture);
                window.draw(plotSprite[i]);
                break;
            default:
            std::cout << "all is well \n";
            break;
        }
        std::cerr << "seven " << i << std::endl;
    }
}

sf::Texture& assets::dereferenceSeed(int seedNum) {
    switch (seedNum) {
        case 1: //strawberry
            return strawberry_tile_texture;
            break;
        case 2: //carrot
            return carrot_tile_texture;
            break;
        case 3: //potato
            return potato_tile_texture;
            break;
        case 4: //cow
            return cow_tile_texture;
            break;
        case 5: //pig
            return pig_tile_texture;
            break;
        case 6: //chicken
            return chicken_tile_texture;
            break;
        default:
            return empty_tile_texture;
            break;
        };
};

void assets::setSeeds(sf::RenderWindow& window) {//shoppable
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
}