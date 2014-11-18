/*
 Game Class
 has players
 has cards
 has tokens
 
 to create game, record players, deal game, 
 change rounds, determine points and if game is over
 
 */

#ifndef pg7_Game_h
#define pg7_Game_h

#include "Marketplace.h"
#include "Player.h"
#include <vector>
#define DECKSIZE 55;

using std::vector;

class Game{
private:
    bool GameOver;   //1 if a player has 2 SoE
    Player[2];       //array of players
    int rounds;
    Marketplace market = new Marketplace;
    
    vector<Card> deck;    //vector deck
    vector<Card> discard;   //discarded cards
    
    vector<Token> bonus3;   //bonus tokens traded for 3 cards
    vector<Token> bonus4;
    vector<Token> bonus5;
    
    vector<Token> clothT;   //cloth tokens
    vector<Token> leatherT;
    vector<Token> spiceT;
    vector<Token> silverT;
    vector<Token> goldT;
    vector<Token> diamondT;
    
    
public:
    
    countSE();  //count Seal of Excellence-->determine game over
    giveSE();   //give SoE at end of round
    addPlayer();
    removePlayer();
    endGame();      //if game over =1
    dealMarket();   //set up tokens and cards
    setupTokens();  //determines order of tokens
    dealHand();     //gives players 5 cards
    
    ~Game();
    
};


#endif
