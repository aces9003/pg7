/*
 Player class
	NOT abstract
 */


#ifndef pg7_Player_h
#define pg7_Player_h

//#include "Game.h"
//#include "Hand.h"
#include "Card.h"
#include "Token.h"
#include <string>
#include <vector>
#include <map>

using std::map;
using std::string;
using std:: vector;
//using Game;

class Player {
public:
    std::string name;    //player name
    int points;     //records points in round
    int seals;      //records #of seals of excellence
    bool hasCamelToken;
    //std::vector<int> handIndices; // Make this in game
    bool isActive;
    
//public:
    //Hand myHand;      //creates vector from hand class;
    //Hand myHerd;
    vector<Card> myHand;
    vector<Card> myHerd;
	vector<Card> tradingCards;
    
    // Constructor
    Player();
    
    // Alternate constructor
    Player(std::string name);
    
    // Accessors with inline definitions
    virtual std::string getName() const { return this->name; };
    virtual int getPoints() const { return this->points; };
    virtual int getSeals() const { return this->seals; };
    //virtual bool getCamel() const { return this->hasCamelToken; };
    
    // Mutators
    virtual void addSeal() {seals++;};
    
    // Player has access to Game (they are friends :-) )
    virtual bool take( vector<Card> *market, vector<Card> *deck, int marketInd);
    //functions to take specific items
    //virtual bool trade(vector<int> *marketIndicesForTrading, vector<int> *handIndicesForTrading, vector<Card>* market);
    virtual bool trade(vector<Card> *market, vector<int> *marketIndicesForTrading, vector<int> *playerIndicesForTrading);
	virtual bool takeCamels(vector<Card> *market, vector<Card> *deck);
    
    virtual bool sellOne(map<string,vector<Token>>* tokenBag, int handInd);
    virtual bool sellMult(vector<int> *handIndicesForSelling,map<string,vector<Token>>* tokenBag);///ask card type when player tries to sell mult
    
    // Public Helper methods
    virtual void addPoint(Token t); //add points to player depending on token achieved
    virtual void populateTradingCards(); // merges myHand + myHerd
    
    // Destructor
    virtual ~Player(); //should deallocate hand automatically
    
protected:
    // isValid methods with inline definitions
    
    // Validates hand size
    //virtual bool isValidHand() { return (this->myHand.getSize() <= 7); };
    virtual bool isValidHand() { return (this->myHand.size() <= 7); };
    
    // Validates sellOne(int handInd)
    //virtual bool isValidSaleOfOne(int handInd) { return ((this->myHand.getCard(handInd).getType() != "Diamonds") && (this->myHand.getCard(handInd).getType() != "Gold") && (this->myHand.getCard(handInd).getType() != "Silver")); };
    virtual bool isValidSaleOfOne(int handInd) { return ((this->myHand.at(handInd).getType() != "Diamonds") && (this->myHand.at(handInd).getType() != "Gold") && (this->myHand.at(handInd).getType() != "Silver")); };
    
    // Validates sellMult()
    virtual bool isValidSaleOfMult(vector<int> *handIndicesForSelling, string tp);
    
    friend class Hand;
};

#endif
