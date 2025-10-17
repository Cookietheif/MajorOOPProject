#include <iostream>
#include "./animals.h"

Animals::Animals()
    : produceRate(0),
      priceAnimal(0),
      priceProduce(0)
{
    entity_Name = "Unnamed Animal";
    entity_ID = 0;
    std::cout << "Animal entity created: " << entity_Name << std::endl;
}


Animals::~Animals() {
    std::cout << "Animal entity destroyed: " << entity_Name << std::endl;
}


