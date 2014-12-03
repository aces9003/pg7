/*
 Game Class
 has players
 has cards
 has tokens
 has marketplace
 
 to create game, record players, deal game,
 change rounds, determine points and if game is over
 
 */

#ifndef pg7_Game_h
#define pg7_Game_h

#include "Marketplace.h"
#include "Player.h"
#include "HPlayer.h"
#include "AIPlayer.h"
#include <vector>
#define DECKSIZE 55;

using std::vector;

class Game{
private:
    bool GameOver;   //1 if a player has 2 SoE
    HPlayer p1;
    AIPlayer p2;
    HPlayer p3;         //cant use p2 and p3 at same time;
    int rounds;
    Marketplace market = new Marketplace;
    
    vector<Card> deck;    //vector deck
    
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
    
    Game();
    void playerTurn(Player p);
    void countSE();  //count Seal of Excellence-->determine game over
    void giveSE();   //give SoE at end of round
    void addPlayer();
    void removePlayer();
    bool endGame();      //if game over =1
    void dealMarket();   //set up tokens and cards
    void setupTokens();  //determines order of tokens
    void dealHand();     //gives players 5 cards
    
    ~Game();
    friend class Hand;
    
};


#endif
