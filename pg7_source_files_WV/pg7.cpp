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
    
    int rounds = 1;
    
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
    
    // HUMAN vs. HUMAN
    if (selectGameType == '1') {
        system("clear");
        
        cout << "What is Player 1's name?: ";
        //getline(cin, p1Name);
        cin >> p1Name;
        
        cout << endl;
        
        cout << "What is Player 2's name?: ";
        cin >> p2Name;
        
    startNewRound:
        if (rounds == 1) {
            Game g1;
            Player p1(p1Name);
            p1.isActive = true;
            Player p2(p2Name);
            p2.isActive = false;
            
            g1.p1 = &p1;
            g1.p2 = &p2;
            
            g1.dealHand();
            
            if (beginGame(&g1) == 1) {
                rounds++;
                goto startNewRound;
            } else {
                return 0;
            }
        } else if (rounds == 2) {
            Game g2;
            Player p3(p1Name);
            p3.isActive = true;
            Player p4(p2Name);
            p4.isActive = false;
            
            g2.p1 = &p3;
            g2.p2 = &p4;
            
            g2.dealHand();
            
            if (beginGame(&g2) == 1) {
                rounds++;
                goto startNewRound;
            } else {
                return 0;
            }
        } else if (rounds == 3) {
            Game g3;
            Player p5(p1Name);
            p5.isActive = true;
            Player p6(p2Name);
            p6.isActive = false;
            
            g3.p1 = &p5;
            g3.p2 = &p6;
            
            g3.dealHand();
            
            if (beginGame(&g3) == 1) {
                rounds++;
                goto startNewRound;
            } else {
                return 0;
            }
        }
        
    } else if (selectGameType == '2') {
      system("clear");
        
        cout << "What is Player 1's name?: ";
        //getline(cin, p1Name);
        cin >> p1Name;
        cout << endl;  
		
    startNewRound:
        if (rounds == 1) {
            Game g1;
            Player p1(p1Name);
            p1.isActive = true;
            AIPlayer p2("AI");
            p2.isActive = false;
            
            g1.p1 = &p1;
            g1.p2 = &p2;
            
            g1.dealHand();
            
            if (beginGame(&g1) == 1) {
                rounds++;
                goto startNewRound;
            } else {
                return 0;
            }
        } else if (rounds == 2) {
            Game g2;
            Player p3(p1Name);
            p3.isActive = true;
            AIPlayer p4("AI");
            p4.isActive = false;
            
            g2.p1 = &p3;
            g2.p2 = &p4;
            
            g2.dealHand();
            
            if (beginGame(&g2) == 1) {
                rounds++;
                goto startNewRound;
            } else {
                return 0;
            }
        } else if (rounds == 3) {
            Game g3;
            Player p5(p1Name);
            p5.isActive = true;
            AIPlayer p6("AI");
            p6.isActive = false;
            
            g3.p1 = &p5;
            g3.p2 = &p6;
            
            g3.dealHand();
            
            if (beginGame(&g3) == 1) {
                rounds++;
                goto startNewRound;
            } else {
                return 0;
            }
        }
        
    } else if (selectGameType =='3') {
        return 0;
    } else {
        system("clear");
        goto startNewGame;
    }

    return 0;
}

