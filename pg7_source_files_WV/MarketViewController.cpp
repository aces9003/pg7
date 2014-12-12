//
//  MarketViewControllerTest.cpp
//  pg7
//
//  Created by Alex Sharata on 11/26/14.
//  Copyright (c) 2014 Alex Sharata. All rights reserved.
//

//#include "Game.cpp"
//#include "Player.cpp"
#include "Game.h"
#include "Player.h"
#include <iostream>
#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>
#include <iomanip>

#include <string>
#include <cstdlib>
#include <sstream>

using std::setw;
using std::left;

using std::string;
using std::istream;
using std::ostream;
using std::cout;
using std::cin;
using std::endl;
using std::getline;

// Pass printAll(Game *g, Player *activePlayer)
void printAll(Game *g, Player *activePlayer);
// Pass printDeckSize(vector<Card> deck)
void printDeckSize(vector<Card> deck);
// Pass printMarket(vector<Card> market)
void printMarket(vector<Card> market);
// Pass printTokenInfo(map<string, vector<Token> *> tokenBag)
void printTokenInfo(map<string, vector<Token> *> tokenBag);
// Pass printPlayerInfo(Player *activePlayer) --> WRITE LOGIC TO TEST FOR ACTIVE PLAYER (same logic in UI)
void printPlayerInfo(Player *activePlayer);
void printSeparationBar();
//Pass printTradingCards(Player *activePlayer);
void printTradingCards(Player *activePlayer);

void printAll(Game *g, Player *activePlayer) {
    system("clear");
    printDeckSize(g->deck);
    printMarket(g->market);
    cout << endl;
    printTokenInfo(g->tokenBag);
    cout << endl;
    printPlayerInfo(activePlayer);
    //cout << endl;
    printSeparationBar();
    cout << endl;
}

void printDeckSize(vector<Card> deck) {
    cout << "DECK SIZE: " << (int)deck.size() << endl;
    cout << endl;
}

void printMarket(vector<Card> market) {
    struct winsize w; // Create winsize types as needed
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

    
    //printf ("lines %d\n", w.ws_row);
    //printf ("columns %d\n", w.ws_col);
    
    //system("clear");
    
    //cout.width((w.ws_col/2) + 13);   // the + 5 centers MARKETPLACE
    cout << "MARKETPLACE" << endl;

    //cout << endl;
    
    // Abbreviations for Marketplace
    // Diamonds = Dmnd
    // Gold = Gold
    // Silver = Slvr
    // Cloth = Clth
    // Spice = Spce
    // Leather = Lthr
    // Camels = Caml

    // Print card bays
    //cout.width((w.ws_col/2) - 23);
    cout << "+" << "————————+————————+————————+————————+————————+" << endl;
    //cout.width((w.ws_col/2) - 23);
    cout << "|" << "   0    |    1   |    2   |    3   |    4   |" << endl;
    //cout.width((w.ws_col/2) - 23);
    cout << "+" << "————————+————————+————————+————————+————————+" << endl;
    //cout.width((w.ws_col/2) - 23);
    cout << "|" << "        |        |        |        |        |" << endl;
    //cout.width((w.ws_col/2) - 23);
    cout << "|" << "        |        |        |        |        |" << endl;
    // Must automate this line
    //cout << "|" << " getCard(); | mple | sample | sample | sample |" << endl;
    //cout.width((w.ws_col/2) - 23);
    
    //cout << "|" << "  Dmnd  | sample | sample | sample | sample |" << endl;
    cout << "|";
    
    for (int i = 0; i < 5; i++) {
        if (market.at(i).getType() == "Diamonds")
            cout << "  Dmnd  |";
        else if (market.at(i).getType() == "Gold")
            cout << "  Gold  |";
        else if (market.at(i).getType() == "Silver")
            cout << "  Slvr  |";
        else if (market.at(i).getType() == "Cloth")
            cout << "  Clth  |";
        else if (market.at(i).getType() == "Spice")
            cout << "  Spce  |";
        else if (market.at(i).getType() == "Leather")
            cout << "  Lthr  |";
        else if (market.at(i).getType() == "Camels")
            cout << "  Caml  |";
    }
    cout << endl;
    
    
    //cout.width((w.ws_col/2) - 23);
    cout << "|" << "        |        |        |        |        |" << endl;
    //cout.width((w.ws_col/2) - 23);
    cout << "|" << "        |        |        |        |        |" << endl;
    //cout.width((w.ws_col/2) - 23);
    cout << "+" << "————————+————————+————————+————————+————————+" << endl;

    //cout << endl;
    
}

// Pass in game so it can access tokens
void printTokenInfo(map<string, vector<Token> *> tokenBag) {
    
    cout << "TOKEN INFO" << endl;
    
    cout << "+" << "———————+———————+———————+———————+———————+———————+———————+———————+———————+" << endl;
    cout << "|" << "Diamnds| Gold  |Silver | Cloth | Spice |Leather|Bonus 3|Bonus 4|Bonus 5| " << endl;
    cout << "+" << "———————+———————+———————+———————+———————+———————+———————+———————+———————+" << endl;
    // MUST AUTOMATE
    cout << "|" << "   " << (int)tokenBag.at("Diamonds")->size() << "   |   " << (int)tokenBag.at("Gold")->size() << "   |   " << (int)tokenBag.at("Silver")->size() << "   |   " << (int)tokenBag.at("Cloth")->size() << "   |   " << (int)tokenBag.at("Spice")->size() << "   |   " << (int)tokenBag.at("Leather")->size() << "   |   " << (int)tokenBag.at("bonus3")->size() << "   |   " << (int)tokenBag.at("bonus4")->size() << "   |   " << (int)tokenBag.at("bonus5")->size() << "   | " << endl;
    cout << "+" << "———————+———————+———————+———————+———————+———————+———————+———————+———————+" << endl;
    
}

// Pass it player so it can print either myHand or tradingCards (depending on take() or trade())
// Camel count
// Points
//void printPlayerInfo(Player *p) {
void printPlayerInfo(Player *activePlayer) {
    // call printCardToScreen() and pass it player that was passed to printHand
    // cout << "Player" << ** current player's number ** << " hand:" << endl;
    // iterate through respective player's hand printing all player's card minus camel cards (don't center the cards)

    // Print active player's info:
    cout << activePlayer->getName() << "'s Hand:" << endl;
    for (int i = 0; i < (int)activePlayer->myHand.size(); i++) {
        cout << " [" << i << "] " << activePlayer->myHand.at(i).getType() << endl;
    }
    
    cout << endl;
    
    cout << activePlayer->getName() << "'s Herd Size: " << (int)activePlayer->myHerd.size() <<endl;
    
    cout << activePlayer->getName() << "'s Points: " << activePlayer->getPoints() << endl;
    
    cout << activePlayer->getName() << "'s Seals of Excellence: " << activePlayer->getSeals() << endl;
}


void printSeparationBar() {
    struct winsize w; // Create winsize types as needed
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    
    // Marketplace separation bar
    cout.fill('_');
    cout.width(w.ws_col);
    cout << std::left << "_" << '\n';
}


void printTradingCards(Player *activePlayer) {
    // Print active player's tradingCards:
    cout << "All of " << activePlayer->getName() << "'s Cards: " << endl;
    for (int i = 0; i < (int)activePlayer->tradingCards.size(); i++) {
        cout << " [" << i << "] " << activePlayer->tradingCards.at(i).getType() << endl;
    }
}

