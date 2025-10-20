#ifndef DISEASE_H
#define DISEASE_H

#include "event.h"

class disease : public event {
    public:
    disease();
    void spin();
};

#endif