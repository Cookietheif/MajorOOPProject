#include "event.h"
#include "drought.h"
#include "pests.h"

int main(){
    event* e = new event();
    pests* d = new pests();
    e = d;
    e->spin();
}