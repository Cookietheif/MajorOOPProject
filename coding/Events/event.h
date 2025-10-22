#ifndef EVENT_H
#define EVENT_H
#include <random>
#include <iostream>
#include <cmath>
#include <chrono>

class event {
    protected:
    int likelihood;

    public:
    event();
    virtual double spin(); // virtual function for event implementation
};

#endif