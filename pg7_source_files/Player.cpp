//
//  Player.cpp
//  
//
//  Created by Alex Sharata on 12/3/14.
//
//

#include "Player.h"
#include <stdio.h>

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
        }
    }
    
    if (camelsInMarket > 0) {
        return true
    } else return false;
}

