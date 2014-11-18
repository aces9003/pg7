/*
 Player Class
 has cards
 has tokens
 
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
    take();
//functions to take specific items
    take1(const Card &c);
    takeMult(int cards);
    takeCamel();
    replace1(const Card &c);
    replaceMult(int cards);
    
    sell();
    //functions to sell specific cards
    sell1(const Card &c);
    sellMult(int cards);
    
    addPoint();
    awardCamel();
    
    ~Player();      //need to deallocate hand
};

#endif
