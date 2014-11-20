/*
 ABSTRACT Player Class
 has cards
 has hand
 
 create player, record points, seals, cards
 has all of players actions
 */

#ifndef pg7_Player_h
#define pg7_Player_h
#include "Cards.h"
#include "Hand.h"
#define MAXSIZE 7

class Player{
    
private:
    string name;    //player name
    int points;     //records points in round
    int seals;      //records #of seals of excellence
    Hand mine= new Hand;      //creates vector from hand class;
    bool hasCamelToken;
    
public:
    Player()
    
    virtual take()=0;
    //functions to take specific items
    virtual trade(int cards)=0;
    virtual take1(const Card &c);
    virtual takeMult(int cards);
    virtual takeCamel();
    virtual replace1(const Card &c);
    virtual replaceMult(int cards);
    
    virtual sell()=0;
    //functions to sell specific cards
    virtual sell1(const Card &c);
    virtual sellMult(int cards);
    
    virtual addPoint();
    virtual awardCamel();
    
    ~Player();      //need to deallocate hand
};

#endif
