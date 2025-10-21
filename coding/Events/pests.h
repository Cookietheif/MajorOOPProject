#ifndef PESTS_H
#define PESTS_H

#include "event.h"

class pests : public event {
    public:
    pests();
    int spin();
};

#endif