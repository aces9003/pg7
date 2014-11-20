/*
 AI Player class
 inheritted from Player class
 */

#include "Player.h"

#ifndef pg7_HPlayer_h
#define pg7_HPlayer_h

class AIPlayer: public Player{
    
private:
    string name;    //player name
    int points;     //records points in round
    int seals;      //records #of seals of excellence
    Hand mine= new Hand;      //creates vector from hand class;
    bool hasCamelToken;
    
public:
    Player()
    
    virtual take();
    //functions to take specific items
    virtual trade(int cards);
    virtual take1(const Card &c);
    virtual takeMult(int cards);
    virtual takeCamel();
    virtual replace1(const Card &c);
    virtual replaceMult(int cards);
    
    virtual sell();
    //functions to sell specific cards
    virtual sell1(const Card &c);
    virtual sellMult(int cards);
    
    virtual addPoint();
    virtual awardCamel();
    
    ~Player();      //need to deallocate hand
};
#endif
