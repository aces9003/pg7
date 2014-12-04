//
//  Player.cpp
//  
//
//  Created by Alex Sharata on 12/3/14.
//
//

#include "Player.h"
#include "Token.h"
#include "Cards.h"
#include <stdio.h>
#include <vector>

// CONSTRUCTORS
// Default constructor - if called, creates 'generic' player
Player:: Player() : name("PlayerX"), points(0), seals(0), hasCamelToken(false) {}

// Alternate constructor - SHOULD be used preferably when first initializing Player objects
Player:: Player(std::string name) {
    this->name = name;  // Get this from user input
    this->points = 0;
    this->seals = 0;
    this->hasCamelToken = false;
}

// MUTATORS
// Takes 1 card from Deck
bool Player::take(Game g, int marketInd)
{
    // run isValidHand to make sure player's hand.size() <= 7
    if (isValidHand()) {
        // adds card to this->myHand from Marketplace (call's hand's addCard() method)
        myHand.addCard(g.market.at(marketInd));
        
        // replaces card that was taken from Marketplace (calls "market's replace" AKA market.replaceCard())
        g.market.replaceCard(marketInd, g.deck.back());
		
		// Delete card from deck
		g.deck.pop_back();
		
        return true;
    } else return false;
    // UI: Print "Your hand is full. Press any key to return to the previous menu..."
}


bool Player::takeCamels(Game g)
{
    int camelsInMarket = 0;
    // Iterature through g.market and find all camels
    for (int i = 0; i < 5; i++) {
        if (g.market.getCard(i).getType() == "Camels") {
            camelsInMarket++;
            myHerd.addCard(g.market.at(i));
            g.market.replaceCard(i, g.deck.back());
			g.deck.pop_back();
        }
    }
    
    if (camelsInMarket > 0) {
        return true;
    } else return false;
}


bool Player::trade(Game g)
{
    
    
}


////DO THIS
// Player has access to Game (they are friends :-) )

    //functions to take specific items    
bool Player::sellOne(int handInd)
{
		// run isValidSaleOfOne to make sure player can sell this card
    	if (isValidSaleOfOne(handInd)) {
			//Card * c= &this.myHand.at(handInd);
			Token myToken;
			//std::string type= c.getType();
			std::string type = myHand.at(handInd).getType();
			if(type=="Cloth"){
				myToken=g.clothT.back();
				g.clothT.pop_back();
			}
			else if(type=="Leather"){
				myToken=g.leatherT.back();
				g.leatherT.pop_back();
			}
			else if(type=="Spice"){
				myToken=g.spiceT.back();
				g.spiceT.pop_back();
			}
			//ERASE CARD FROM HAND
			this.myHand.erase(myHand.begin()+handInd);
			
			//adds points to painter
			points=points+myToken.getPt();
			else {std::Cout<<"Error selling card"<<endl;}
			//free(c);
		}
		
}

bool Player::isValidSaleOfMult(Game g) 
{
	
	
	
}
void Player::sellMult(class Game g);	//need isValidSaleOfMult();
    
void Player::addPoint(class Game g);
void Player::awardCamelToken();
