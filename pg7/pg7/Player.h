/*
 Player Class
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
    
    void take()=0;
    //functions to take specific items
    void trade(int cards)=0;
    void take1(const Card &c);
    void takeMult(int cards);
    void takeCamel();
    void replace1(const Card &c);
    void replaceMult(int cards);
    
    void sell()=0;
    //functions to sell specific cards
    void sell1(const Card &c);
    void sellMult(int cards);
    
    void addPoint();
    void awardCamel();
    
    ~Player();      //need to deallocate hand
};

#endif
