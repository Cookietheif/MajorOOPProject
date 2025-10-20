#ifndef EVENT_H
#define EVENT_H

class event {
    protected:
    double likelihood;
    int duration;
    int eventAge;

    public:
    event();
    virtual void spin();
};

#endif