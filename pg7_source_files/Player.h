/*
 	Player class
	NOT abstract
 */


#ifndef pg7_Player_h
#define pg7_Player_h

#include "Hand.h"
#include "Card.h"
#include "Token.h"
#include <string>
#include <vector>

using std::string;
using std:: vector;

class Player {
	
    std::string name;    //player name
    int points;     //records points in round
    int seals;      //records #of seals of excellence
    Hand myHand;      //creates vector from hand class;
    Hand myHerd;
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
    virtual bool take( Game * g, int marketInd);
    //functions to take specific items
    virtual bool trade( Game * g);
    virtual bool takeCamels( Game * g);
    
    virtual bool sellOne( Game * g, int handInd);
    virtual void sellMult(Game * g);///ask card type when player tries to sell mult
    
	
    virtual void addPoint(Token * t); //add points to player depending on token achieved

    
    // Destructor
    virtual ~Player(){std::cout<<"Deleting Player "<<this->getName()<<std::endl;};//should deallocate hand automatically
    
protected:
    // isValid methods with inline definitions
    
    // Validates hand size
    virtual bool isValidHand() { return (this->myHand().getSize() <= 7); };
    
    // Validates sellOne(int handInd)
    virtual bool isValidSaleOfOne(int handInd) { return ((this->myHand().getCard(handInd).getType() != "Diamonds") && (this->myHand().getCard(handInd).getType() != "Gold") && (this->myHand().getCard(handInd).getType() != "Silver")); }; 
    
    // Validates sellMult()
    virtual bool isValidSaleOfMult( Game * g, string tp);
    
    friend class Hand;
};

#endif
