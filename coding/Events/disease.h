#ifndef DISEASE_H
#define DISEASE_H

#include "event.h"

class disease : public event {
    public:
    disease();
    double spin(); // overiding virtual function
};

#endif