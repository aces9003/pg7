/*
 	Player class
	NOT abstract
 */


#ifndef pg7_Player_h
#define pg7_Player_h

#include "Game.h"
//#include "Hand.h"
#include "Card.h"
#include "Token.h"
#include <string>
#include <vector>

using std::string;
using std:: vector;
//using Game;

class Player {
	
    std::string name;    //player name
    int points;     //records points in round
    int seals;      //records #of seals of excellence
   // Hand myHand;      //creates vector from hand class;
    //Hand myHerd;
	vector<Card> myHand, myHerd;
    bool hasCamelToken;
    //std::vector<int> handIndices; // Make this in game
    
public:
    // Constructor
    Player();
    
    // Alternate constructor
    Player(std::string name);
    
    // Accessors with inline definitions
    virtual std::string getName() const { return this->name; };
    virtual int getPoints() const { return this->points; };
    virtual int getSeals() const { return this->seals; };
    virtual bool getCamel() const { return this->hasCamelToken; };
    
    // Mutators
    
    // Player has access to Game (they are friends :-) )
    virtual bool take( vector<Card> market, vector<Card> deck, int marketInd);
    //functions to take specific items
    virtual bool trade();
    virtual bool takeCamels(vector<Card> market, vector<Card> deck);
    
    virtual bool sellOne( vector<Token> clothT, vector<Token> leatherT, vector<Token> spiceT, int handInd);
    virtual void sellMult(vector<int> handIndicesForSelling, vector<Token> bonus3, vector<Token> bonus4, vector<Token> bonus5,vector<Token> clothT, vector<Token> leatherT, vector<Token> spiceT, vector<Token> diamondT, vector<Token> goldT, vector<Token> silverT);///ask card type when player tries to sell mult
    
	
    virtual void addPoint(Token t); //add points to player depending on token achieved

    
    // Destructor
    virtual ~Player(){std::cout<<"Deleting Player "<<this->getName()<<std::endl;};//should deallocate hand automatically
    
protected:
    // isValid methods with inline definitions
    
    // Validates hand size
    //virtual bool isValidHand() { return (this->myHand.getSize() <= 7); };
	virtual bool isValidHand() { return (this->myHand.size() <= 7); };
    
    // Validates sellOne(int handInd)
    //virtual bool isValidSaleOfOne(int handInd) { return ((this->myHand.getCard(handInd).getType() != "Diamonds") && (this->myHand.getCard(handInd).getType() != "Gold") && (this->myHand.getCard(handInd).getType() != "Silver")); };
	virtual bool isValidSaleOfOne(int handInd) { return ((this->myHand.at(handInd).getType() != "Diamonds") && (this->myHand.at(handInd).getType() != "Gold") && (this->myHand.at(handInd).getType() != "Silver")); };
    
    // Validates sellMult()
    virtual bool isValidSaleOfMult(vector<int> handIndicesForSelling, string tp);
    
    friend class Hand;
};

#endif
