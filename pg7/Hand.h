/*
 Hand Class
 has cards
 creats hand of cards --a vector with max length 7
 */

#ifndef pg7_Hand_h
#define pg7_Hand_h

#include "Container.h"

class Hand : public Container{

protected:
    vector<Card> hand;
public:
    Hand();
    virtual ~Hand();
    virtual print();
};

#endif
