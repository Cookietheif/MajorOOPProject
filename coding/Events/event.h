#ifndef EVENT_H
#define EVENT_H
#include <random>
#include <iostream>
#include <cmath>
#include <chrono>
#include "gameState.h"

class event {
    protected:
    int likelihood;
    int duration;
    int eventAge;

    public:
    event();
    virtual int spin();
};

#endif