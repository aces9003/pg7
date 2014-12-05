// HandTest.cpp
// compile with g++ -std=c++11 -pedantic -Wall -Wextra -O HandTest.cpp Hand.cpp Card.cpp
// Append *.cpp files as you see necessary for testing purposes

#include "Hand.h"
//#include "Hand.cpp"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <assert.h>

using std::cout;
using std::endl;

void createDeck();
// temp deck for testing
vector<Card> deck;

int main() {
    // First make a shuffled deck to test with
    createDeck();
    
    // Make a Hand object to test
	Hand testHand1; // should properly create Hand object for teesting
	Hand testHand2();

	return 0;
}

void createDeck(){ //include all 55 cards in deck container
    
    //create 9 leather cards
    for (int i=0;i<9;i++){
        string leather = "Leather";
        Card card(leather);
        deck.push_back(card);
    }
    //create 8 spice cards
    for (int i=0;i<8;i++){
        string spice = "Spice";
        Card card(spice);
        deck.push_back(card);
    }
    //create 6 cloth cards
    for (int i=0;i<6;i++){
        string cloth = "Cloth";
        Card card(cloth);
        deck.push_back(card);
    }
    //create 6 silver cards
    for (int i=0;i<6;i++){
        string silver = "Silver";
        Card card(silver);
        deck.push_back(card);
    }
    //create 6 gold cards
    for (int i=0;i<6;i++){
        string gold = "Gold";
        Card card(gold);
        deck.push_back(card);
    }
    //create 6 diamonds cards
    for (int i=0;i<6;i++){
        string diamond = "Diamonds";
        Card card(diamond);
        deck.push_back(card);
    }
    //create 11 camels cards
    for (int i=0;i<11;i++){
        string camel = "Camels";
        Card card(camel);
        deck.push_back(card);
    }
    
    // Shuffle deck
    std::random_shuffle ( deck.begin(), deck.end() );
    
    // Add three camel to back of deck for marketplace setup
    for (int i=0;i<3;i++){
        string camel = "Camels";
        Card card(camel);
        deck.push_back(card);
    }
}
