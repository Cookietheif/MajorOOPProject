#ifndef PESTS_H
#define PESTS_H

#include "event.h"

class pests : public event {
    public:
    pests();
    void spin();
};

#endif