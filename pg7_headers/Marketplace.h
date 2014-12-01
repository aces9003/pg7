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
    vector<Card> market;
    
public:
    Marketplace();
    virtual ~Marketplace(){market.clear};
    Card getCard(int place)const{return market.at(place);} ;  //place is spot in vector. first place ==0
    std::string* getMarket();
    void addCard(Card c)const {market.push_back(c);};
};

#endif
