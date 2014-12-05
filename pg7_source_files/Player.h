/*
 	Player class
	NOT abstract
 */

#include "Card.h"
#include "Hand.h"
#include <string>
#include <vector>

#ifndef pg7_Player_h
#define pg7_Player_h

using std::string;
using std:: vector;

class Player {
	
    std::string name;    //player name
    int points;     //records points in round
    int seals;      //records #of seals of excellence
    Hand myHand = new Hand;      //creates vector from hand class;
    Hand myHerd = new Hand;
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
    virtual int getSeals{} const { return this->seals; };
    virtual bool getCamel() const { return this->hasCamelToken; };
    
    // Mutators
    
    // Player has access to Game (they are friends :-) )
    virtual bool take(class Game g, int marketInd);
    //functions to take specific items
    virtual bool trade(class Game g);
    virtual bool takeCamels(class Game g);
    
    virtual bool sellOne(int handInd);
    virtual void sellMult(class Game g);///ask card type when player tries to sell mult
    
    virtual void addPoint(class Game g);
    virtual void awardCamelToken();
    
    // Destructor
    virtual ~Player();      //need to deallocate hand
    
protected:
    // isValid methods with inline definitions
    
    // Validates hand size
    virtual bool isValidHand() { return (this->myHand.size <= 7); };
    
    // Validates sellOne(int handInd)
    virtual bool isValidSaleOfOne(int handInd) { return ((this->myHand.at(handInd).getType() != "Diamonds") && (this->myHand.at(handInd).getType() != "Gold") && (this->myHand.at(handInd).getType() != "Silver"); }; 
    
    // Validates sellMult()
    virtual bool isValidSaleOfMult(class Game g, string tp);
    
    friend class Hand;
};

#endif
