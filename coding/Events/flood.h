#ifndef FLOOD_H
#define Flood_H

#include "event.h"

class flood : public event {
    public:
    flood();    
    double spin(); // overiding virtual function
};

#endif