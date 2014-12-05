//AIPlayer.cpp
//  
//
//  Created by Alex Sharata on 12/3/14.
//
//emily

#include "Player.h"
#include "Card.h"
#include "Token.h"
#include <stdio.h>

// CONSTRUCTORS
// Default constructor - if called, creates 'generic' player
AIPlayer:: AIPlayer() : name("AIPlayer"), points(0), seals(0), hasCamelToken(false) {}


AIPlayer:: AIPlayer(std::string name){
    this->name=name;
	this->points=0;
	this->points=0;
	this->hasCamelToken=false;
}

void AIPlayer::makeTurn(Game * g){
	int randPick = rand() % 4;
	if(randPick==0 && this.myHand<7){
		//take
		int r= rand() % g.market.size();
		take(g, r);
	}
	else if(randPick==1){
		//trade
		trade(g);		//CHECK ONCE ALEX IS DONE
	}
	else if(randPick==2){
		//sell one 
	}
	else if(randPick==3){ //&& check is valid to sell mult){
		//sell multiple 
	}
	else{
		std::cout<<"Error in picking a move"<<endl;
	}
}
			
void ~AIPlayer(){
	std::cout<<"Deleting AIPlayer "<<this.getName()<<std::endl;
}

/*
// MUTATORS
// Takes 1 card from Deck
bool AIPlayer::take(Game g)
{	
	int marketInd= rand % 5;
    // run isValidHand to make sure player's hand.size() <= 7
    if (isValidHand()) {
        // adds card to this->myHand from Marketplace (call's hand's addCard() method)
        myHand.addCard(g.market.at(marketInd));
        
        // replaces card that was taken from Marketplace (calls "market's replace" AKA market.replaceCard())
        g.market.replaceCard(marketInd, g.deck.back());
		
		/// Delete card from deck
		g.deck.pop_back();
        
        return true;
    } else return false;
    // UI: Print "Your hand is full. Press any key to return to the previous menu..."
}

bool Player::trade(Game g)
{
    
    
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

*/
			