/*
/////////////////////////////////////////////////
//RESTRUCTURE MARKETPLACE.H TO FIX CONSTRUCTORS//
/////////////////////////////////////////////////

 Marketplace Class
 has cards
 
 holds cards in vector with contant length 5
 
 */

#ifndef pg7_Marketplace_h
#define pg7_Marketplace_h

#include "Container.h"
#include "Game.h"
#include "Card.h"
#include <vector>
#include <iostream>

using std::vector;

class Marketplace: public Container{
protected:
    vector<Card> market;
    
public:
	Marketplace(){};
    Marketplace(vector<Card> &deck);
    bool isValid(){ return (market.size()==5);};
    virtual ~Marketplace(){market.clear();};
    Card getCard(int place){return market.at(place);} ;  //place is spot in vector. first place ==0
    //std::string* getMarket(); // returns array of 5 strings with current market cards (used for printing to UI)
    // Only called 5 times when initializing market from deck at beginning of every round:
    void addCard(Card * c) {market.push_back(c);};
    // Called every time there is a transaction with the market
    void replaceCard(int Ind,  Card * c){ market.at(Ind)=c;};
};

#endif
