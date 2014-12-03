/*
 Hand Class
 inheritted from Container class
 has cards
 creates hand of cards --a vector with max length 7
 */

#ifndef pg7_Hand_h
#define pg7_Hand_h

#include <vector>
#include "Game.h"
#include "Container.h"
#include <iostream>
#include <string>
using std::ostream;
using std::string;
using std::vector;

class Hand : public Container{
    
private:
    int camels;
    vector<Card> hand;
public:
    
    Hand(Game a);
    bool isValid(){if(hand.size()<=7 && hand.size()>=0) return true; else return false;};
    virtual ~Hand(){hand.clear();};
    Card getCard(int place)const{return hand.at(place);} ;  //place is spot in vector. first place ==0
    std::string* getHand();
    void addCard(Card c) {hand.push_back(c);};
    
};

#endif
