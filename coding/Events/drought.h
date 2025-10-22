#ifndef DROUGHT_H
#define DROUGHT_H

#include "event.h"

class drought : public event {
    public:
    drought();
    double spin(); // overiding virtual function
};

#endif
