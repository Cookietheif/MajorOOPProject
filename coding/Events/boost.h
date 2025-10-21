#ifndef BOOST_H
#define BOOST_H

#include "event.h"

class boost : public event {
    public:
    boost();
    int spin();
};

#endif