#include "crops.h"
#include <iostream>


Crops::Crops()
    : yield(0),
      buyPrice(0),
      growthTime(0),
      currentAge(0)
{
    entity_Name = "Unnamed Crop";
    entity_ID = 0;
    std::cout << "Crop entity created: " << entity_Name << std::endl;
}


Crops::~Crops() {
    std::cout << "Crop entity destroyed: " << entity_Name << std::endl;
}


void Crops::grow() {
    if (currentAge < growthTime) {
        currentAge++;
    }
}


bool Crops::isReadyToHarvest() const {
    return currentAge >= growthTime;
}
