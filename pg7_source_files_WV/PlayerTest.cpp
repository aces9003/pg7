//PlayerTest.cpp
// compile with g++ -std=c++11 -pedantic -Wall -Wextra -O PlayerTest.cpp Card.cpp Token.cpp
//

#include "Player.h"
#include "Player.cpp"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <assert.h>

using std::cout;
using std::endl;

void createDeck();
void fakeDealMarket();
void printMarket();
// temp deck for testing
vector<Card> deck;
vector<Card> market;

int main() {
    createDeck();
    fakeDealMarket();
    
    Player first = Player();
    Player second;
    
    Player withName("testplayer");
    
    // Print market
    printMarket();
    
    assert(first.takeCamels(&market, &deck));
    // Print first's hand
    cout << "Herd size: " << first.myHerd.size() << endl;
    for (int i = 0; i < (int) first.myHerd.size(); i++) {
        cout << first.myHerd.at(i).getType() << endl;
    }
    
    printMarket();
    
    //assert(second.take(market, deck, 1));
    // Print second's hand
    //cout << second.myHand.at(0).getType() << endl;
    
    //assert(withName.take(market, deck, 2));
    // Print withName's hand
    //cout << withName.myHand.at(0).getType() << endl;
    
}

void printMarket() {
    // Print market
    cout << "|" << market.at(0).getType() << "|"<< market.at(1).getType() << "|" << market.at(2).getType() << "|" << market.at(3).getType() << "|" << market.at(4).getType() << "|" <<endl;
}

void fakeDealMarket() {
    for (int i = 0; i < 5; i++) {
        market.push_back(deck.back());
        deck.pop_back();
    }
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
    /*
    for (int i=0;i<3;i++){
        string camel = "Camels";
        Card card(camel);
        deck.push_back(card);
    }
     */
    Card camelCard1("Camels1");
    Card camelCard2("Camels2");
    Card camelCard3("Camels3");
    
    deck.push_back(camelCard1);
    deck.push_back(camelCard2);
    deck.push_back(camelCard3);
    
}
