//AIPlayer.cpp
//  
//
//  Created by Alex Sharata on 12/3/14.
//
//emily

#include "AIPlayer.h"
#include "Player.h"
#include "Card.h"
#include "Token.h"
#include <stdio.h>
//#include <map>
#include <string>

//using std::map;
using std::string;

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
	if(randPick==0 && this->myHand.getSize()<7){
		//take
		int r= rand() % (int)market().getSize();
		take(&(g->market), &(g->deck), r);
	}
	else if(randPick==1){
		//trade
		randPick = 2; //just makes it sell one if lands on trade
		//trade(g);		//CHECK ONCE ALEX IS DONE
	}
	else if(randPick==2){
		//sell one 
		int randPickHand = srand() % (int)myHand.size; // need to seed random?
		sellOne(&(g->tokenBag),randPickHand);
	}
	else if(randPick==3){ //&& check is valid to sell mult){
		//sell multiple 
		std::string sellType;
		int sellTypeNum=0;
		if (hand.size>1){
			for (int i=0;i<(int)myHand.size();i++){
				std::string typeTemp;
				typeTemp = myHand.at(i).getType();
				countTemp =0;
				
				//gets all types in hand and keeps track of largest set
				for (int j=0; j<myHand.size(); j++){
					if (myHand.at(j).getType() == typeTemp){
						countTemp++;
					}
				}
				if (countTemp>sellTypeNum){
					sellTypeNum = countTemp;
					sellType = typeTemp;
				}
			}
			for (int x=0;x<(int)myHand.size();x++){
				if (myHand.at(x).getType == sellType){
					handIndicesForSelling.push_back(x);
				}
				if (isValidSaleOfMult(&handIndicesForSelling, sellType)){
					sellMult(&handIndicesForSelling,&(g->tokenBag));
				}
			}
		}
		else{
			//switches to take if randomly lands on multi and cannot sell muli
			int r= rand() % (int)market().getSize();
			take(&(g->market), &(g->deck), r);
		}
	}
	else{
		for (int i=0;i<(int)myHand.size();i++){
			if (isValidSaleOfOne(i)){
				sellOne(&(g->tokenBag),i);
				break;
			}
		}
	}
}

AIPlayer::~AIPlayer(){
	std::cout<<"Deleting AIPlayer "<<std::endl;
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
			