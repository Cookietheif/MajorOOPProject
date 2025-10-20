#ifndef EVENT_H
#define EVENT_H
#include <random>
#include <iostream>
#include <cmath>
#include <chrono>

class event {
    protected:
    int likelihood;
    int duration;
    int eventAge;

    public:
    event();
    virtual void spin();
};

#endif