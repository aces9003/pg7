/*
 ABSTRACT Container Class
 has Cards
 vector for cards
 */

#ifndef pg7_Container_h
#define pg7_Container_h

#include "Cards.h"
#include <vector>

 using std::vector;

class Container{
protected:
    std::vector<Card> container;
public:
    virtual ~Container();
    virtual void addCard(Card c)const=0;
    virtual Card getCard(int place)const=0;
};

#endif
