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
#define DECKSIZE 55;

#include "Marketplace.h"
#include "Player.h"
#include <vector>

using std::vector;

class Game{
private:
    bool GameOver;   //1 if a player has 2 SoE
    Player[2];       //array of players
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
    
    // User input storage variables
    int currentUserInput;
    
    // Trading vectors -- to be used respectively by current player
    vector<int> marketIndicesForTrading;
    vector<int> handIndicesForTrading;
    
    // Selling vectors -- to be used respectively by current player as well
    vector<int> handIndicesForSelling;
    
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
    friend class Marketplace;
    friend class Player;
    
};


#endif
