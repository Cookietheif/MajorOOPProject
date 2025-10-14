#ifndef EVENT_H
#define EVENT_H

#include <string>

class event {
    protected:
    double likelihood;
    int duration;

    public:
    event();
    virtual void hit();
    ~event();
};

#endif