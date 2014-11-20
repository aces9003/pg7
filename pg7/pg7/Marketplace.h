/*
 Marketplace Class
 has cards
 
 holds cards in vector with contant length 5
 
 */

#ifndef pg7_Marketplace_h
#define pg7_Marketplace_h

#include "Container.h"

class Marketplace: public Container{
protected:
    vector<Card> hand;
    
public:
    Marketplace();
    virtual print();
    
    ~Marketplace();
};

#endif
