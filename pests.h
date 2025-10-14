#ifndef PESTS_H
#define PESTS_H
#include "event.h"

class pests : public event{
    public:
    pests();
    int hit(int monthlyProfit);
    ~pests();
};

#endif