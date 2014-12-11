//
//  MarketViewControllerTest.cpp
//  pg7
//
//  Created by Alex Sharata on 11/26/14.
//  Copyright (c) 2014 Alex Sharata. All rights reserved.
//

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
void printAll();
// Pass printMarket(vector<Card> market)
void printMarket();
// Pass printTokenInfo(ALL TOKEN VECTORS)
void printTokenInfo();
// Pass printPlayerInfo(Player *activePlayer) --> WRITE LOGIC TO TEST FOR ACTIVE PLAYER (same logic in UI)
void printPlayerInfo();
void printSeparationBar();

void printAll() {
    system("clear");
    printMarket();
    cout << endl;
    printTokenInfo();
    cout << endl;
    printPlayerInfo();
    cout << endl;
    printSeparationBar();
    cout << endl;
}

void printMarket() {
    struct winsize w; // Create winsize types as needed
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

    
    //printf ("lines %d\n", w.ws_row);
    //printf ("columns %d\n", w.ws_col);
    
    //system("clear");
    
    //cout.width((w.ws_col/2) + 13);   // the + 5 centers MARKETPLACE
    cout << "MARKETPLACE (DECK SIZE: #)" << endl;

    //cout << endl;

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
    cout << "|" << " sample | sample | sample | sample | sample |" << endl;
    //cout.width((w.ws_col/2) - 23);
    cout << "|" << "        |        |        |        |        |" << endl;
    //cout.width((w.ws_col/2) - 23);
    cout << "|" << "        |        |        |        |        |" << endl;
    //cout.width((w.ws_col/2) - 23);
    cout << "+" << "————————+————————+————————+————————+————————+" << endl;

    //cout << endl;
    
}

// Pass in game so it can access tokens
void printTokenInfo() {
    
    cout << "TOKEN INFO" << endl;
    
    cout << "+" << "———————+———————+———————+———————+———————+———————+———————+———————+———————+" << endl;
    cout << "|" << "Diamnds| Gold  |Silver | Cloth | Spice |Leather|Bonus 3|Bonus 4|Bonus 5| " << endl;
    cout << "+" << "———————+———————+———————+———————+———————+———————+———————+———————+———————+" << endl;
    // MUST AUTOMATE
    cout << "|" << "   #   |   #   |   #   |   #   |   #   |   #   |   #   |   #   |   #   | " << endl;
    cout << "+" << "———————+———————+———————+———————+———————+———————+———————+———————+———————+" << endl;
    
}

// Pass it player so it can print either myHand or tradingCards (depending on take() or trade())
// Camel count
// Points
//void printPlayerInfo(Player *p) {
void printPlayerInfo() {
    // call printCardToScreen() and pass it player that was passed to printHand
    // cout << "Player" << ** current player's number ** << " hand:" << endl;
    // iterate through respective player's hand printing all player's card minus camel cards (don't center the cards)

    // Print active player's info:
    cout << "p.name" << "'s Info:" << endl;
}


void printSeparationBar() {
    struct winsize w; // Create winsize types as needed
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    
    // Marketplace separation bar
    cout.fill('_');
    cout.width(w.ws_col);
    cout << std::left << "_" << '\n';
}
