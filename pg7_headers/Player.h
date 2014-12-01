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
    std::string name;    //player name
    int points;     //records points in round
    int seals;      //records #of seals of excellence
    Hand mine= new Hand;      //creates vector from hand class;
    bool hasCamelToken;
    
public:
    Player()=0;
    
    virtual void getName()=0;
    virtual void getPoints()=0;
    virtual void getSeals()=0;
    virtual void getCamel()=0;
    
    virtual void take()=0;
    //functions to take specific items
    virtual void trade(int cards)=0;
    virtual void take1(const Card &c);
    virtual void takeMult(int cards);
    virtual void takeCamel();
    virtual void replace1(const Card &c);
    virtual void replaceMult(int cards);
    
    virtual void sell()=0;
    //functions to sell specific cards
    virtual void sell1(const Card &c);
    virtual void sellMult(int cards);
    
    virtual void addPoint();
    virtual void awardCamel();
    
    virtual ~Player();      //need to deallocate hand
};

#endif
