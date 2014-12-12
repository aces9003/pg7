// GameTest.cpp
// compile with g++ -std=c++11 -pedantic -Wall -Wextra -O pg7.cpp Card.cpp Token.cpp Player.cpp
// Append *.cpp files as you see necessary for testing purposes

#include "DynamicViewController.cpp"
#include "Game.h"
#include "Game.cpp"
//#include "Player.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <assert.h>

using std::cout;
using std::endl;

int main() {
startNewGame:
    // Get names for players
    system("clear");
    
    char selectGameType;
    string p1Name;
    string p2Name;
    
    p1Name.clear();
    p2Name.clear();
    
    cout << "Welcome to Emily, Matthias, and Alex's Jaipur!\n";
    cout << "::Please select your game type below::\n\n"
    
    << " 1) Human vs. Human\n"
    << " 2) Human vs. Computer\n"
    << " 3) Exit Game\n"
    << "Selection: ";
    cin >> selectGameType;
    
    //system("clear");
    cout << endl; cout << endl;
    
    if (selectGameType == '1') {
        system("clear");
        
        cout << "What is Player 1's name?: ";
        //getline(cin, p1Name);
        cin >> p1Name;
        
        cout << endl;
        
        cout << "What is Player 2's name?: ";
        cin >> p2Name;
        
        Game g;
        Player p1(p1Name);
        p1.isActive = true;
        Player p2(p2Name);
        p2.isActive = false;
        
        g.p1 = &p1;
        g.p2 = &p2;
        
        g.dealHand();
        
        beginGame(&g);
    } else if (selectGameType == '2') {
        
        //Game g;
        //Player p1("p1");
        //p1.isActive = true;
        //AIPlayer p2("AI");
        //p3.isActive = true;
        
       // g.dealHand();
    } else if (selectGameType =='3') {
        return 0;
    } else {
        system("clear");
        goto startNewGame;
    }

    return 0;
}

