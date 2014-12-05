/*
 Hand Class
 inheritted from Container class
 has cards
 creates hand of cards --a vector with max length 7
 */

#ifndef pg7_Hand_h
#define pg7_Hand_h

#include "Container.h"
//#include "Game.h"
#include <vector>
#include <iostream>
#include <string>

using std::ostream;
using std::string;
using std::vector;

class Hand : public Container{
	
    vector<Card> hand;
	
public:
	// Constructors
	// Default contstructor
    Hand();
	// Alternate constructor
    //Hand(class Game a, class Player p);
	
	// Destructor - virtual (definition should be in Hand.cpp)
    virtual ~Hand();
	
	// Accessors
    Card getCard(int place) const { return hand.at(place); };  //place is spot in vector. first place ==0
    //std::string* getHand(); //--> NEEDS TO BE USED IN UI LATER
	
	// Mutators (definitions should be in Hand.cpp)
    void addCard(Card c);

private:
	// Helper methods
	// isValid method with inline definition
	bool isValid() { return (hand.size() <= 7); };
};

#endif
