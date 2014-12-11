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

//#include "Marketplace.h"
#include "Player.h"
//#include "Player.cpp"
//#include "AIPlayer.h"
#include "Token.h"
#include "Card.h"
#include <vector>
#include <map>
#include <string>

using std::map;
using std::vector;
//using Player;
//class AIPlayer;
class Player;


class Game{
private:
    bool GameOver;   //1 if a player has 2 SoE
public: // for now...
    Player * p1;
    Player * p2;
    //AIPlayer * p3;       //cant use p2 and p3 at same time;
private:
    //bool isAi;
	int rounds;
    //Marketplace market();
    vector<Card> market;
	
	 // User input storage variables
    int currentUserInput;
	
public:
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
	
	map<string, vector<Token>> tokenBag = {{"bonus3", bonus3},{"bonus4", bonus4},{"bonus5", bonus5},
    {"Cloth", clothT},{"Leather", leatherT},{"Spice", spiceT},{"Sliver", silverT},
    {"Gold", goldT},{"Diamonds", diamondT}};
    
    // Trading vectors -- to be used respectively by current player
    vector<int> marketIndicesForTrading;
    vector<int> playerIndicesForTrading;
    
    // Selling vectors -- to be used respectively by current player as well
    vector<int> handIndicesForSelling;
   
	// Constructor
    // Default Constructor
	//Game();
    
	// Alternate Constructor
	Game(std::string name1, std::string name2);
	
    // Accessors
    int getCurrentUserInput() const { return this->currentUserInput; };
    
    
    // Mutators
    bool setCurrentUserInput(int n) { currentUserInput = n; return true; };
    
    void playerTurn(Player &p);
    //int countSE(const AIPlayer & p);  //count Seal of Excellence-->determine game over
    void giveSE(const Player & p);   //give SoE at end of round to given player
    bool initPlayers(std::string name1, std::string name2);     // Desctruct players in Game destructor using Player's destructor
    bool endGame();      //if game over =1
    void dealMarket();   //set up tokens and cards
    void setupTokens();  //determines order of tokens
    void dealHand();     //gives players 5 cards
    void createDeck();   //initialize deck
	void awardCammelToken(); //make has camel token bool true and check each player's herd size
    
    ~Game();
    
    friend class Hand;
    friend class Marketplace;
    friend class Player;
	//friend class AIPlayer;
    
private:
    // Helper methods
    
    // isValidMarket
    bool isValidMarket() { return (this->market.size() < 6); };
    
};


#endif
