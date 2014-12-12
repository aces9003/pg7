//
//  DynamicViewController.cpp
//  pg7
//
//  Created by Alex Sharata on 12/8/14.
//  Copyright (c) 2014 Alex Sharata. All rights reserved.
//

#include "MarketViewController.cpp"
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

using std::string;
using std::istream;
using std::ostream;
using std::cout;
using std::cin;
using std::endl;
using std::getline;


// Should take Game pointer object to pass to methods within
void beginGame(Game *g) {
//void beginGame() {
    
    system("clear");
    
    while (true) {
        // P1 gets first turn
        Player *activePlayer = g->p1;
    startNewTurn:
        system("clear");
        
        //===============
        // CHECK IF ROUND OR GAME IS OVER UP HERE... IF IT IS, PRINT WINNER/AWARD SOEs
        // Use g->isRoundOver() and g->isGameOver()
        //===============


        
        // EACH TIME WE goto(StartMainMenu), reset activePlayer
        // *activePlayer will point to, and alter, the player it's pointing to
        
        // TEMP FIX:
        //Player *activePlayer = g->p1;
        
        
        if (g->p1->isActive) {
            activePlayer = (g->p1);
        //} else if (g->p2->isActive) {
        } else if (g->p2->isActive) {
            activePlayer = (g->p2);
        }
        
    startMainMenu:
        system("clear");
        
        string mainMenuInput;
        mainMenuInput.clear();
        char singleCharInput = '\0';
        
        printAll(g, activePlayer);
        //————————————————————————————————
        cout << activePlayer->getName() <<"'s Turn\n";
        cout << "=======================\n";
        cout << "::Main Menu::\n\n"
        
        << " 1) Take\n"
        << " 2) Trade\n"
        << " 3) Sell\n"
        << "Selection: ";
        getline(cin, mainMenuInput);
        
        // Check to make sure only one character was input by user
        if (mainMenuInput.length() > 1) {
            system("clear");
            printAll(g, activePlayer);
            //————————————————————————————————
            cout << "Invalid Input Entered\n\n";
            system( "read -n 1 -s -p \"Press any key to return to the main menu...\"" );
            system("clear");
            goto startMainMenu;
        } else {
            singleCharInput = mainMenuInput[0];
        }
        
        system("clear");
        
    startSwitch:
        switch (singleCharInput) {
                
                
                
            ////////////////////////
            // ------ TAKE ------ //
            ////////////////////////
                
            case '1': {
                system("clear");
                printAll(g, activePlayer);
                //————————————————————————————————
                
                char takeOptions;
                cout << "::Take Options::\n\n"
                << " 1) Take One Card\n"
                << " 2) Take Camels\n"
                << " 3) Return to Main Menu\n"
                << "Selection: ";
                cin >> takeOptions;
                cout << endl;
                
                if (takeOptions > '3' || takeOptions < '1') {
                    cout << "Invalid Input Entered\n\n";
                    system( "read -n 1 -s -p \"Press any key to return to the previous menu...\"" );
                    singleCharInput = '1';
                    system("clear");
                    goto startSwitch;
                } else if (takeOptions == '1') {
                    // TAKE ONE args = (&market, &deck, marketInd)
                    // first check handsize of activePlayer < 7, then allow to take card
                    string marketIndexChar;
                    int marketIndexInt;
                    
                    if (activePlayer->myHand.size() < 7) {
                        cout << "What card do you want from the market?: ";
                        cin >> marketIndexChar;
                        marketIndexInt = stoi(marketIndexChar);
                    
                        if (marketIndexInt > 5 || marketIndexInt < 0) {
                        //if (marketIndexInt > (g->market.size() - 1) || marketIndexInt < 0) {
                            cout << "The card indices you specified do not exist in the market!\n\n";
                            system( "read -n 1 -s -p \"Press any key to return to the previous menu...\"" );
                            singleCharInput = '1';
                            system("clear");
                        } else {
                            activePlayer->take(&(g->market), &(g->deck), marketIndexInt);
                            system("clear");
                            printAll(g, activePlayer);
                            //————————————————————————————————
                            cout << "Done.\n";
                            system( "read -n 1 -s -p \"Press any key to start the other player's turn...\"" );
                            system("clear");
                            
                            // CHANGES ACTIVE PLAYER
                            if (g->p1->isActive) {
                                g->p1->isActive = false;
                                g->p2->isActive = true;
                                goto startNewTurn;
                            } else if (g->p2->isActive) {
                                g->p2->isActive = false;
                                g->p1->isActive = true;
                                goto startNewTurn;
                            }
                        }
    
                    } else {
                    // Too many cards in hand to take another...
                         cout << "Your hand is full!\n\n";
                         system( "read -n 1 -s -p \"Press any key to return to the previous menu...\"" );
                         singleCharInput = '1';
                         system("clear");
                         goto startSwitch;
                    }
                
                } else if (takeOptions == '2') {
                    // TAKE CAMELS args = (&market, &deck);
                    // First check to see if there are camels in the market
                    int camelsInMarketCount = 0;
                    
                    for (int i = 0; i < (int)g->market.size(); i++) {
                        if (g->market.at(i).getType() == "Camels")
                            camelsInMarketCount++;
                    }
                    
                    if (camelsInMarketCount > 0) {
                        activePlayer->takeCamels(&(g->market), &(g->deck));
                        system("clear");
                        printAll(g, activePlayer);
                        //————————————————————————————————
                        cout << "Done.\n";
                        system( "read -n 1 -s -p \"Press any key to start the other player's turn...\"" );
                        system("clear");
                        
                        // CHANGES ACTIVE PLAYER
                        if (g->p1->isActive) {
                            g->p1->isActive = false;
                            g->p2->isActive = true;
                            goto startNewTurn;
                        } else if (g->p2->isActive) {
                            g->p2->isActive = false;
                            g->p1->isActive = true;
                            goto startNewTurn;
                        }
                        
                    } else {
                        // No camels in market
                        cout << "Sorry, there are currently no camels in the market.\n\n";
                        system( "read -n 1 -s -p \"Press any key to return to the previous menu...\"" );
                        singleCharInput = '1';
                        system("clear");
                        goto startSwitch;
                    }
                    
                } else if (takeOptions == '3') {
                    // RETURN
                    system("clear");
                    goto startMainMenu;
                } else {
                    cout << "Invalid Input Entered\n\n";
                    system( "read -n 1 -s -p \"Press any key to return to the previous menu...\"" );
                    singleCharInput = '1';
                    system("clear");
                    goto startSwitch;
                }
                
            } break;
            
                
                
            /////////////////////////
            // ------ TRADE ------ //
            /////////////////////////
                
            case '2': {
            
            } break;
                
                
            
            ////////////////////////
            // ------ SELL ------ //
            ////////////////////////
                
            case '3': {
                system("clear");
                printAll(g, activePlayer);
                //————————————————————————————————
                
                char sellOptions;
                cout << "::Sell Options::\n\n"
                << " 1) Sell One Card\n"
                << " 2) Sell Multiple Cards\n"
                << " 3) Return to Main Menu\n"
                << "Selection: ";
                cin >> sellOptions;
                cout << endl;
                
                if (sellOptions > '3' || sellOptions < '1') {
                    cout << "Invalid Input Entered\n\n";
                    system( "read -n 1 -s -p \"Press any key to return to the previous menu...\"" );
                    singleCharInput = '3';
                    system("clear");
                    goto startSwitch;
                } else if (sellOptions == '1') {
                    // SELL ONE args = (&ALL TOKEN VECTORS, handInd)
                    // first check handsize of activePlayer > 0, then allow to sell card
                    string handIndexChar;
                    int handIndexInt;
                    
                    if (activePlayer->myHand.size() > 0) {
                        cout << "What card do you want to sell from your hand?: ";
                        cin >> handIndexChar;
                        handIndexInt = stoi(handIndexChar);
                        
                        if (handIndexInt > (int)(activePlayer->myHand.size() - 1) || handIndexInt < 0) {
                            cout << "The card index you specified does not exist in your hand!\n\n";
                            system( "read -n 1 -s -p \"Press any key to return to the previous menu...\"" );
                            singleCharInput = '3';
                            system("clear");
                            goto startSwitch;
                        } else {
                            if (activePlayer->sellOne(&(g->tokenBag), handIndexInt)) {
                                system("clear");
                                printAll(g, activePlayer);
                                //————————————————————————————————
                                cout << "Done.\n";
                                system( "read -n 1 -s -p \"Press any key to start the other player's turn...\"" );
                                system("clear");
                                
                                // CHANGES ACTIVE PLAYER
                                if (g->p1->isActive) {
                                    g->p1->isActive = false;
                                    g->p2->isActive = true;
                                    goto startNewTurn;
                                } else if (g->p2->isActive) {
                                    g->p2->isActive = false;
                                    g->p1->isActive = true;
                                    goto startNewTurn;
                                }
                            } else {
                                cout << "You cannot sell only one of this type of card.\n\n";
                                system( "read -n 1 -s -p \"Press any key to return to the previous menu...\"" );
                                singleCharInput = '3';
                                system("clear");
                                goto startSwitch;
                            }
                        }
                    
                    } else {
                        // No cards to sell...
                        cout << "Your hand is empty!\n\n";
                        system( "read -n 1 -s -p \"Press any key to return to the previous menu...\"" );
                        singleCharInput = '3';
                        system("clear");
                        goto startSwitch;
                    }
                
                } else if (sellOptions == '2') {
                    // SELL MULT args = (vector<int> *handIndicesForSelling, *tokenBag)
                    // first check handsize of activePlayer > 0, then allow to sell card
                    
                    if (activePlayer->myHand.size() > 0) {
                        cout << "What card do you want to sell from your hand (Space out indices and type any non-numeric character to terminate)?: ";
                        int marketIndForSelling;
                        for (int i = 0; i < (int)activePlayer->myHand.size(); i++) {
                            cin >> marketIndForSelling;
                            (g->handIndicesForSelling).push_back(marketIndForSelling);
                        }

                        
                        if ((int)(g->handIndicesForSelling).size() > (int)(activePlayer->myHand.size()) || (int)(g->handIndicesForSelling).size() == 0) {
                            cout << "The card index you specified does not exist in your hand!\n\n";
                            system( "read -n 1 -s -p \"Press any key to return to the previous menu...\"" );
                            singleCharInput = '3';
                            system("clear");
                            goto startSwitch;
                        } else {
                            if (activePlayer->sellMult(&(g->handIndicesForSelling), &(g->tokenBag))) {
                                system("clear");
                                printAll(g, activePlayer);
                                //————————————————————————————————
                                cout << "Done.\n";
                                system( "read -n 1 -s -p \"Press any key to start the other player's turn...\"" );
                                system("clear");
                                
                                // CHANGES ACTIVE PLAYER
                                if (g->p1->isActive) {
                                    g->p1->isActive = false;
                                    g->p2->isActive = true;
                                    goto startNewTurn;
                                } else if (g->p2->isActive) {
                                    g->p2->isActive = false;
                                    g->p1->isActive = true;
                                    goto startNewTurn;
                                }
                            } else {
                                cout << "You cannot sell these cards. Try again.\n\n";
                                system( "read -n 1 -s -p \"Press any key to return to the previous menu...\"" );
                                singleCharInput = '3';
                                system("clear");
                                goto startSwitch;
                            }
                        }
                        
                    } else {
                        // No cards to sell...
                        cout << "Your hand is empty!\n\n";
                        system( "read -n 1 -s -p \"Press any key to return to the previous menu...\"" );
                        singleCharInput = '3';
                        system("clear");
                        goto startSwitch;
                    }
                    
                } else if (sellOptions == '3') {
                    // RETURN
                    system("clear");
                    goto startMainMenu;
                } else {
                    cout << "Invalid Input Entered\n\n";
                    system( "read -n 1 -s -p \"Press any key to return to the previous menu...\"" );
                    singleCharInput = '1';
                    system("clear");
                    goto startSwitch;
                }
                
            } break;
            
                /*
            default:
                break;
                 */
        }

        
    }
    
    
}
