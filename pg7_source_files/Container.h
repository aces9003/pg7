/*
 ABSTRACT Container Class
 has Cards
 vector for cards
 */

#ifndef pg7_Container_h
#define pg7_Container_h

#include "Card.h"
#include <vector>

 using std::vector;

class Container{
protected:
    std::vector<Card> container;
public:
    virtual ~Container();
    virtual void addCard(Card * c) =0;
    virtual Card getCard(int place)=0;
};

#endif
