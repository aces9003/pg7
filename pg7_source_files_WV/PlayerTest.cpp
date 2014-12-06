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

vector<int> marketIndiciesForTrading;
vector<int> handIndicesForTrading;

int main() {
    createDeck();
    fakeDealMarket();
    
    Player p1("Player1");
    Player p2("Player2");
    
    // Print market
    printMarket();
    
    p1.takeCamels(&market, &deck);
    // Print first's hand
    cout << "Herd size: " << p1.myHerd.size() << endl;
    for (int i = 0; i < (int) p1.myHerd.size(); i++) {
        cout << p1.myHerd.at(i).getType() << endl;
    }
    
    cout<<endl; cout<<endl;
    
    printMarket();
    
    // Take Gold
    p1.take(&market, &deck, 1);
    for (int i = 0; i < (int) p1.myHand.size(); i++) {
        cout << p1.myHand.at(i).getType() << endl;
    }
    
    cout<<endl; cout<<endl;
    
    printMarket();
    
    p1.take(&market, &deck, 2);
    for (int i = 0; i < (int) p1.myHand.size(); i++) {
        cout << p1.myHand.at(i).getType() << endl;
    }
    
    cout<<endl; cout<<endl;
    
    printMarket();
    
    p1.take(&market, &deck, 0);
    for (int i = 0; i < (int) p1.myHand.size(); i++) {
        cout << p1.myHand.at(i).getType() << endl;
    }
    
    cout<<endl; cout<<endl;
    
    printMarket();
    
    // Populate trading vectors
    marketIndiciesForTrading.at(0) = 0;
    marketIndiciesForTrading.at(1) = 1;
    marketIndiciesForTrading.at(2) = 2;
    
    handIndicesForTrading.at(0) = 0;
    handIndicesForTrading.at(1) = 1;
    handIndicesForTrading.at(2) = 2;
    
    p1.trade(&marketIndiciesForTrading, &handIndicesForTrading, &market);
    for (int i = 0; i < (int) p1.myHand.size(); i++) {
        cout << p1.myHand.at(i).getType() << endl;
    }
    
    cout<<endl; cout<<endl;
    
    printMarket();
    
    
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
    for (int i=0;i<3;i++){
        string camel = "Camels";
        Card card(camel);
        deck.push_back(card);
    }
    
}
