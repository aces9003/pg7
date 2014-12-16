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
#include <algorithm>
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
using std::iterator;

// Should take Game pointer object to pass to methods within
int beginGame(Game *g) {
//void beginGame() {
    
    system("clear");
    
    while (true) {
        // P1 gets first turn
        Player *activePlayer = g->p1;
        
    startNewTurn:
        system("clear");
        
        // EACH TIME WE goto(StartMainMenu), reset activePlayer
        // *activePlayer will point to, and alter, the player it's pointing to
        
        if (g->p1->isActive) {
            activePlayer = (g->p1);
            //} else if (g->p2->isActive) {
        } else if (g->p2->isActive) {
            activePlayer = (g->p2);
        }
        
        //===============
        // CHECK IF ROUND OR GAME IS OVER UP HERE... IF IT IS, PRINT WINNER/AWARD SOEs
        // Use g->isRoundOver() and g->isGameOver()
        //===============
        
        
        if ((int)(g->deck).size() == 0) {
            if (g->p1->getPoints() > g->p2->getPoints()) {
                g->p1->addSeal();
                // PRINT WINNER
                system("clear");
                cout << endl;
                cout << "=======================================================" << endl;
                cout << "//-- " << g->p1->getName() << " has won this round! " << " --//" << endl;
                cout << "=======================================================" << endl;
                system( "read -n 1 -s -p \"Press any key to start the next round...\"" );
                system("clear");
                goto endRound1;
            } else if (g->p2->getPoints() > g->p1->getPoints()) {
                g->p2->addSeal();
                // PRINT WINNER
                system("clear");
                cout << endl;
                cout << "=======================================================" << endl;
                cout << "//-- " << g->p2->getName() << " has won this round! " << " --//" << endl;
                cout << "=======================================================" << endl;
                system( "read -n 1 -s -p \"Press any key to start the next round...\"" );
                system("clear");
                goto endRound1;
            }
            // INCREMENT ROUND COUNT (in main)
            // NEW GAME INSTANCE (in main)
        endRound1:
            return 1;
        }
        
        // If token vectors are empty
        /*
        for (auto i = g->tokenBag.begin(); i != g->tokenBag.end(); ++i) {
            if ((int)(i->second->size()) == 0) {
                (g->emptyTokenVectors)++;
            }
        }
         */
        
        
        if ((int)(g->diamondT).size() == 0) {
            (g->emptyTokenVectors)++;
        } else if ((int)(g->goldT).size() == 0) {
            (g->emptyTokenVectors)++;
        } else if ((int)(g->silverT).size() == 0) {
            (g->emptyTokenVectors)++;
        } else if ((int)(g->spiceT).size() == 0) {
            (g->emptyTokenVectors)++;
        } else if ((int)(g->leatherT).size() == 0) {
            (g->emptyTokenVectors)++;
        } else if ((int)(g->clothT).size() == 0) {
            (g->emptyTokenVectors)++;
        }
        
        
        // CHECK emptyTokenVectors
        if ((g->emptyTokenVectors) >= 3) {
            if (g->p1->getPoints() > g->p2->getPoints()) {
                g->p1->addSeal();
                // PRINT WINNER
                system("clear");
                cout << endl;
                cout << "=======================================================" << endl;
                cout << "//-- " << g->p1->getName() << " has won this round! " << " --//" << endl;
                cout << "=======================================================" << endl;
                system( "read -n 1 -s -p \"Press any key to start the next round...\"" );
                system("clear");
                goto endRound2;
            } else if (g->p2->getPoints() > g->p1->getPoints()) {
                g->p2->addSeal();
                // PRINT WINNER
                system("clear");
                cout << endl;
                cout << "=======================================================" << endl;
                cout << "//-- " << g->p2->getName() << " has won this round! " << " --//" << endl;
                cout << "=======================================================" << endl;
                system( "read -n 1 -s -p \"Press any key to start the next round...\"" );
                system("clear");
                goto endRound1;
            }
            // INCREMENT ROUND COUNT (in main)
            // NEW GAME INSTANCE (in main)
        endRound2:
            return 1;
        }
        
        // CHECK ENDGAME
        if (g->p1->getSeals() >= 2) {
            // PRINT WINNER
            system("clear");
            cout << endl;
            cout << "=======================================================" << endl;
            cout << "//-- " << g->p1->getName() << " has won JAIPUR! Congrats, you are now the Maharaja's Personal Trader! " << " --//" << endl;
            cout << "=======================================================" << endl;
            
            return 0;
        } else if (g->p2->getSeals() >= 2) {
            // PRINT WINNER
            system("clear");
            cout << endl;
            cout << "=======================================================" << endl;
            cout << "//-- " << g->p2->getName() << " has won JAIPUR! Congrats, you are now the Maharaja's Personal Trader! " << " --//" << endl;
            cout << "=======================================================" << endl;
            
            return 0;
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
                system("clear");
                printAll(g, activePlayer);
                //————————————————————————————————
                
                printTradingCards(activePlayer);
                cout << endl;
                
                char tradeOptions;
                cout << "::Trade Options::\n\n"
                << " 1) Continue with Trade?\n"
                << " 2) Return to Main Menu\n"
                << "Selection: ";
                cin >> tradeOptions;
                cout << endl;
                
                if (tradeOptions > '2' || tradeOptions < '1') {
                    cout << "Invalid Input Entered\n\n";
                    system( "read -n 1 -s -p \"Press any key to return to the previous menu...\"" );
                    singleCharInput = '2';
                    system("clear");
                    goto startSwitch;
                } else if (tradeOptions == '1') {
                    // TRADE args = (&market, &marketIndicesForTrading, &playerIndicesForTrading)
                    // first check handsize of activePlayer > 0, then allow to trade card
                    
                    string tradingIndices;
                    char tradeIndFSChar;
                    int tradeIndFSInt;
                    
                    if (activePlayer->tradingCards.size() > 0) {
                        
                        /////////////////////////////////////
                        ////// playerIndicesForTrading //////
                        /////////////////////////////////////
                        cout << "What cards do you want to trade from your hand?\n"
                        << "(Enter the indices with or without spaces and hit ENTER to trade. NUMBERS ONLY.): ";
                        std::ws(cin);
                        getline(cin, tradingIndices);
                        
                        cout << endl;
                        
                        // POPULATING INDICES VECTOR (playerIndicesForTrading) -- could probably move to a separate function... or nah
                        
                        // Clear Indices vector for good measure
                        (g->playerIndicesForTrading).clear();
                        (g->marketIndicesForTrading).clear();
                        
                        // Convert chars to ints and populate g->playerIndicesForTrading
                        for (int i = 0; i < (int)tradingIndices.size(); i++) {
                            tradeIndFSChar = tradingIndices[i];
                            if (!isspace(tradeIndFSChar)) {   // && if temp is within proper index range for respective vector being populated
                                tradeIndFSInt = atoi(&tradeIndFSChar);
                                if ((tradeIndFSInt >= 0) && (tradeIndFSInt < ((int)activePlayer->tradingCards.size()))) {
                                    (g->playerIndicesForTrading).push_back(tradeIndFSInt);
                                } else {
                                    cout << "One or more of the card indices you specified was invalid!\n\n";
                                    system( "read -n 1 -s -p \"Press any key to return to the previous menu...\"" );
                                    singleCharInput = '2';
                                    system("clear");
                                }
                            }
                        }
                        
                        /////////////////////////////////////
                        ////// marketIndicesForTrading //////
                        /////////////////////////////////////
                        tradingIndices.clear();
                        
                        cout << "What cards do you want from the market? Make sure to specify the same number of cards as above.\n"
                        << "(Enter the indices with or without spaces and hit ENTER to trade. NUMBERS ONLY.): ";
                        std::ws(cin);
                        getline(cin, tradingIndices);
                        
                        // POPULATING INDICES VECTOR (marketIndicesForTrading) -- could probably move to a separate function... or nah
                        
                        // Convert chars to ints and populate g->marketIndicesForTrading
                        for (int i = 0; i < (int)tradingIndices.size(); i++) {
                            tradeIndFSChar = tradingIndices[i];
                            if (!isspace(tradeIndFSChar)) {   // && if temp is within proper index range for respective vector being populated
                                tradeIndFSInt = atoi(&tradeIndFSChar);
                                if ((tradeIndFSInt >= 0) && (tradeIndFSInt < ((int)g->market.size()))) {
                                    (g->marketIndicesForTrading).push_back(tradeIndFSInt);
                                } else {
                                    cout << "One or more of the card indices you specified was invalid!\n\n";
                                    system( "read -n 1 -s -p \"Press any key to return to the previous menu...\"" );
                                    singleCharInput = '2';
                                    system("clear");
                                }
                            }
                        }
                    
                        //////////////////////////////////////////////////////////////////
                        // CHECK FOR DUPLICATES IN INDICES VECTOR(s)
                        // cout << "Duplicates are being eliminated... For testing purposes comment this out" << endl;
                        for (int i = 0; i < (int)(g->playerIndicesForTrading).size() - 1; i++) {
                            std::unique( (g->playerIndicesForTrading).begin(), (g->playerIndicesForTrading).end() );
                        }
                        
                        for (int i = 0; i < (int)(g->marketIndicesForTrading).size() - 1; i++) {
                            std::unique( (g->marketIndicesForTrading).begin(), (g->marketIndicesForTrading).end() );
                        }
                        //////////////////////////////////////////////////////////////////
                        
                        if (((g->playerIndicesForTrading).size()) != ((g->marketIndicesForTrading).size())) {
                            cout << "The number of cards you want to trade from your hand to the market do not match up. Try Again.\n\n";
                            system( "read -n 1 -s -p \"Press any key to return to the previous menu...\"" );
                            singleCharInput = '2';
                            system("clear");
                        }
                        
                        if (((g->playerIndicesForTrading).size() > activePlayer->tradingCards.size()) || ((g->marketIndicesForTrading).size() > (g->market).size()) || (int)(g->playerIndicesForTrading).size() == 0 || (int)(g->marketIndicesForTrading).size() == 0) {
                            cout << "You selected ivalid card indices from your hand or from the market. Try Again.\n\n";
                            system( "read -n 1 -s -p \"Press any key to return to the previous menu...\"" );
                            singleCharInput = '2';
                            system("clear");
                            goto startSwitch;
                        } else {
                            if (activePlayer->trade(&(g->market), &(g->marketIndicesForTrading), &(g->playerIndicesForTrading))) {
                                // MAKE SURE TO CLEAR vectors just in case
                                (g->marketIndicesForTrading).clear();
                                (g->playerIndicesForTrading).clear();

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
                                cout << "You cannot trade these cards. Try again.\n\n";
                                system( "read -n 1 -s -p \"Press any key to return to the previous menu...\"" );
                                singleCharInput = '2';
                                system("clear");
                                goto startSwitch;
                            }
                        }
                        
                    } else {
                        // No cards to trade...
                        cout << "Your hand is empty!\n\n";
                        system( "read -n 1 -s -p \"Press any key to return to the previous menu...\"" );
                        singleCharInput = '2';
                        system("clear");
                        goto startSwitch;
                    }
                    
                } else if (tradeOptions == '2') {
                    // RETURN
                    system("clear");
                    goto startMainMenu;
                } else {
                    cout << "Invalid Input Entered\n\n";
                    system( "read -n 1 -s -p \"Press any key to return to the previous menu...\"" );
                    singleCharInput = '2';
                    system("clear");
                    goto startSwitch;
                }
                
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
                    
                    string handIndicesFS;
                    char handIndFSChar;
                    int handIndFSInt;
                    
                    if (activePlayer->myHand.size() > 0) {
                        cout << "What cards do you want to sell from your hand?\n"
                             << "(Enter the indices with or without spaces and hit ENTER to sell. NUMBERS ONLY.): ";
                        std::ws(cin);
                        getline(cin, handIndicesFS);
                        
                        // POPULATING INDICES VECTOR (handIndicesForSelling) -- could probably move to a separate function... or nah
                        
                        // Clear Indices vector for good measure
                        (g->handIndicesForSelling).clear();
                        
                        // Convert chars to ints and populate g->handIndicesForSelling
                        for (int i = 0; i < (int)handIndicesFS.size(); i++) {
                            handIndFSChar = handIndicesFS[i];
                            if (!isspace(handIndFSChar)) {   // && if temp is within proper index range for respective vector being populated
                                handIndFSInt = atoi(&handIndFSChar);
                                if ((handIndFSInt >= 0) && (handIndFSInt < ((int)activePlayer->myHand.size()))) {
                                    (g->handIndicesForSelling).push_back(handIndFSInt);
                                } else {
                                    cout << "One or more of the card indices you specified was invalid!\n\n";
                                    system( "read -n 1 -s -p \"Press any key to return to the previous menu...\"" );
                                    singleCharInput = '3';
                                    system("clear");
                                }
                            }
                        }
                        
                        // CHECK FOR DUPLICATES IN INDICES VECTOR(s)
                        // cout << "Duplicates are being eliminated... For testing purposes comment this out" << endl;
                        for (int i = 0; i < (int)(g->handIndicesForSelling).size() - 1; i++) {
                            std::unique( (g->handIndicesForSelling).begin(), (g->handIndicesForSelling).end() );
                        }
                        
                        
                        if (((g->handIndicesForSelling).size() > activePlayer->myHand.size()) || (int)(g->handIndicesForSelling).size() == 0) {
                            cout << "The card index you specified does not exist in your hand!\n\n";
                            system( "read -n 1 -s -p \"Press any key to return to the previous menu...\"" );
                            singleCharInput = '3';
                            system("clear");
                            goto startSwitch;
                        } else {
                            if (activePlayer->sellMult(&(g->handIndicesForSelling), &(g->tokenBag))) {
                                // MAKE SURE TO CLEAR handIndicesForSelling just in case
                                (g->handIndicesForSelling).clear();
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
                    singleCharInput = '3';
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