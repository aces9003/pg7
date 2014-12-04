/*
 Human Player class
 inheritted from Player class
 */

#include "Hand.h"
#include <string>
#include <vector>

#ifndef pg7_Player_h
#define pg7_Player_h

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
    
    // Accessors with inline definitions
    std::string getName() const { return this->name; };
    int getPoints() const { return this->points; };
    int getSeals{} const { return this->seals; };
    bool getCamel() const { return this->hasCamelToken; };
    
    // Mutators
    
    // Player has access to Game (they are friends :-) )
    bool take(Game g, int marketInd);
    //functions to take specific items
    bool trade(Game g);
    bool takeCamels(Game g);
    
    void sell();
    //functions to sell specific cards
    //void sellOne(const Card &c);
    bool sellOne(int handInd);
    void sellMult(int cards);
    
    void addPoint();
    void awardCamel();
    
    // Destructor
    virtual ~Player();      //need to deallocate hand
    
private:
    // isValid methods with inline definitions
    
    // Validates hand size
    bool isValidHand() { if (this->myHand.size <= 7) return true; else return false; };
    
    // Validates sellOne(int handInd)
    bool isValidSaleOfOne();
    
    // Validates sellMult()
    
    friend class Hand;
};

#endif
